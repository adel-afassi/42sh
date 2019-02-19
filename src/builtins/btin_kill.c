/*
** btin_kill.c for  in /home/youcef/delivery/PSU/42sh
** 
** Made by youcef chergui
** Login   <youcef.chergui@epitech.net>
** 
** Started on  Tue Apr 11 15:10:00 2017 youcef chergui
** Last update Fri Apr 14 18:03:41 2017 youcef chergui
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include "42sh.h"
#include "helpers/output.h"
#include "helpers/number.h"
#include "helpers/string.h"
#include "helpers/array.h"
#include "my_signal.h"
#include "builtins/btin_kill.h"

/*
** Execute the 'kill' builtin
** @param current_stdout (the output where the message will be display)
** @param args (an array which contains the command and its parameters)
** @param env (an array of t_list pointers which contain the environment)
** @return check_signal (an int which contains the return code of the fonction)
*/
int	btin_kill(int current_stdout, char **args, t_list **env)
{
  int	i;

  (void)env;
  i = 0;
  if (array_len(args) < 2)
    {
      print_error(BTIN_KILL_BAD_ARG_NB);
      return (1);
    }
  while (args[i] != NULL)
    {
      if (my_strcmp(args[i], "-l") == 0)
	{
	  return (show_siglist(current_stdout));
	}
      i = i + 1;
    }
  return (check_signal(args));
}

/*
** Check if an other signal than KILL is sent to processes
** @param args (an array which contains the command and its parameters)
** @return code (an int which contains the return code of the fonction)
*/
int	check_signal(char **args)
{
  int	code;
  int	signal;

  code = 0;
  if (is_num(args[1]) == 2)
    return (bad_arg_or_sig(args, &code));
  signal = is_signal(&(args[1][1]));
  if (args[1][0] == '-')
    {
      if (signal != -1)
	{
	  code = send_signals_to_process(args, signal);
	}
      else
	print_kill_error(args[1], &code, BTIN_KILL_UNKNOWN_SIGNAL);
    }
  else
    print_kill_error("", &code, BTIN_KILL_BAD_ARG);
  return (code);
}

/*
** Send the chosen signal to all the processes
** @param args (an array which contains the command and its parameters)
** @param signal (the chosen signal)
** @return code (an int which contains the return code of the fonction)
*/
int	send_signals_to_process(char **args, int signal)
{
  int	i;
  int	code;

  i = 2;
  code = 0;
  while (args[i] != NULL)
    {
      if (is_num(args[i]) != 2)
	print_kill_error("", &code, BTIN_KILL_BAD_ARG);
      else
	{
	  if ((kill(my_getnbr(args[i]), signal)) == -1)
	    {
	      perror(args[i]);
	      code = 1;
	    }
	  else
	    code = 0;
	}
      i = i + 1;
    }
  return (code);
}

/*
** Send the KILL signal to all the processes
** @param args (an array which contains the command and its parameters)
** @param code (an pointer on int to stock the return code)
** @return *code (an int which contains the return code of the fonction)
*/
int	bad_arg_or_sig(char **args, int *code)
{
  int	i;

  i = 1;
  while (args[i] != NULL)
    {
      if (is_num(args[i]) != 2)
	{
	  print_kill_error("", code, BTIN_KILL_BAD_ARG);
	  return (*code);
	}
      else
	if ((kill(my_getnbr(args[i]), SIGKILL)) == -1)
	  {
	    perror(args[i]);
	    *code = 1;
	  }
      i += 1;
    }
  return (*code);
}

/*
** Print the chosen message on the error output
** @param args (the prefix of the message)
** @param code (an pointer on int to stock the return code)
** @param message (the message to display (which contains ':' as prefix)
*/
void	print_kill_error(char *args, int *code, char *message)
{
  if (args[0] == '-')
    print_error(&args[1]);
  else
    print_error(args);
  print_error(message);
  *code = 1;
}
