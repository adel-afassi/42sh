/*
** main.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src
**
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
**
** Started on  Tue Jan 17 01:05:24 2017 Jérémy Sid Idris
** Last update Tue Apr 18 17:12:09 2017 adel
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "helpers/output.h"
#include "helpers/list.h"
#include "helpers/memory.h"
#include "utils/get_next_line.h"
#include "input.h"
#include "parser.h"
#include "home.h"
#include "config_rc.h"
#include "42sh.h"

int			main(int argc, char **argv, char **env)
{
  struct termios	term;
  t_list		*env_list;
  int			code;

  (void)(argc);
  (void)(argv);
  catching_signals();
  if (isatty(0) == 1)
    {
      if (term_handling(&term) == -1)
	exit(print_error(TERM_SETUP_FAIL_ERROR));
    }
  env_list = import_list(env);
  load_42shrc(env_list);
  code = shell_loop(env_list);
  jfree_remaining(ALLOC);
  return (code);
}

int		shell_loop(t_list *env_list)
{
  t_input	line;
  char		*buffer;
  int		code;

  if (isatty(0) == 1)
    {
      init_struct(&line);
      show_prompt();
      while ((buffer = interactive_get_next_line(&line)) != NULL)
	{
	  my_putchar('\n');
	  code = line_parser(buffer, &env_list);
	  jfree_remaining(LINE_ALLOC);
	  rm_line(&line);
	  show_prompt();
	}
      return (code);
    }
  else
    {
      while ((buffer = get_next_line(0)) != NULL)
	{
	  code = line_parser(buffer, &env_list);
	  jfree_remaining(LINE_ALLOC);
	}
      return (code);
    }
}

void	catching_signals()
{
  signal(SIGINT, &sigint_message);
  signal(SIGQUIT, SIG_IGN);
}

void	sigint_message()
{
  my_putchar('\n');
  show_prompt();
}

void	show_prompt()
{
  char	*dir;

  if (isatty(0) == 1)
    {
      dir = jmalloc(sizeof(char) * 1024, LINE_ALLOC);
      getcwd(dir, 1024);
      my_putstr(1, dir);
      my_putstr(1, "> ");
      jfree(dir);
    }
}
