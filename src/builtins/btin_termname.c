/*
** btin_termname.c for  in /home/youcef/delivery/PSU/42sh
** 
** Made by youcef chergui
** Login   <youcef.chergui@epitech.net>
** 
** Started on  Fri Apr 14 18:32:02 2017 youcef chergui
** Last update Fri Apr 14 19:52:52 2017 youcef chergui
*/

#include <stdlib.h>
#include <stdio.h>
#include "helpers/output.h"
#include "helpers/number.h"
#include "helpers/string.h"
#include "helpers/array.h"
#include "env.h"
#include "42sh.h"
#include "builtins/btin_termname.h"

/*
** Execute the 'termname' builtin
** @param current_stdout (the output where the message will be display)
** @param args (an array which contains the command and its parameters)
** @param env (an array of t_list pointers which contain the environment)
** @return code (an int which contains the return code of the builtin)
*/
int	btin_termname(int current_stdout, char **args, t_list **env)
{
  int	code;
  char	*term;

  code = 0;
  if (array_len(args) <= 3)
    {
      if (array_len(args) == 2 && my_strcmp(args[1], "xterm") == 0)
	my_putstr(current_stdout, "xterm\n");
      else if (array_len(args) == 1)
	{
	  if ((term = get_env_value("TERM", *env)) == NULL)
	    code = 1;
	  else
	    {
	      my_putstr(current_stdout, term);
	      my_putstr(current_stdout, "\n");
	    }
	}
    }
  else
    {
      print_error("termname: Too many arguments.\n");
      code = 1;
    }
  return (code);
}
