/*
** btin_echo.c for  in /home/youcef/delivery/PSU/42sh/src/builtins
** 
** Made by youcef chergui
** Login   <youcef.chergui@epitech.net>
** 
** Started on  Mon Apr 10 21:57:42 2017 youcef chergui
** Last update Tue May  2 22:41:46 2017 Youcef
*/

#include <stdlib.h>
#include "helpers/output.h"
#include "helpers/number.h"
#include "helpers/string.h"
#include "helpers/array.h"
#include "helpers/output.h"
#include "42sh.h"
#include "builtins/btin_echo.h"

/*
** Execute the 'echo' builtin
** @param current_stdout (the output where the message will be display)
** @param args (an array which contains the command and its parameters)
** @param env (an array of t_list pointers which contain the environment)
** @return 0 (the 'echo' builtin always success)
*/
int	btin_echo(int current_stdout, char **args, t_list **env)
{
  int	i;

  (void)(env);
  i = 1;
  if (array_len(args) > 1 && my_strcmp(args[i], "-n") == 0)
    i = 2;
  while (args[i] != 0)
    {
      my_putstr(current_stdout, args[i]);
      if (args[i + 1])
	my_putstr(current_stdout, " ");
      i = i + 1;
    }
  if (array_len(args) > 1 && my_strcmp(args[1], "-n") != 0)
    my_putstr(current_stdout, "\n");
  if (array_len(args) == 1)
    my_putstr(current_stdout, "\n");
  return (0);
}
