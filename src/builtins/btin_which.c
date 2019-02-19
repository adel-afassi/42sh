/*
** btin_which.c for  in /home/adel/delivery/42sh/src/builtins/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Apr 12 15:54:49 2017 John Doe
** Last update Mon May  1 19:14:41 2017 adel
*/

#include <stdlib.h>
#include "builtins/btin_which.h"
#include "helpers/output.h"
#include "helpers/file.h"
#include "helpers/array.h"
#include "builtin.h"
#include "binary.h"
#include "path.h"

/*
** builtin which
** @param current_stdout (int containing the sdtout for the function my_putstr)
** @param args (char ** containing the command and his arguments)
** @param env (a linked list pointer containing the env)
** @return code (return int containing the last status function or 1 if error)
*/
int	btin_which(int current_stdout, char **args, t_list **env)
{
  int	i;
  int	code;

  i = 1;
  code = 0;
  if (btin_which_validate(args, current_stdout) == 1)
    return (1);
  while (args[i] != NULL)
    {
      if (is_builtin(args[i]))
	builtin_msg(args[i], 1, current_stdout);
      else if (check_file_exist(args[i]))
	{
	  my_putstr(current_stdout, args[i]);
	  my_putstr(current_stdout, "\n");
	}
      else if (it_is_binary(args[i], env, current_stdout));
      else
	{
	  builtin_msg(args[i], 2, current_stdout);
	  code = 1;
	}
      i = i + 1;
    }
  return (code);
}

int	it_is_binary(char *arg, t_list **env, int current_stdout)
{
  char	*path;

  if (is_binary(arg, *env))
    {
      if ((path = find_realpath(arg, *env)) != NULL)
	{
	  if (arg[0] != '/')
	    {
	      my_putstr(current_stdout, path);
	      my_putstr(current_stdout, "\n");
	      return (1);
	    }
	}
    }
  return (0);
}

int	builtin_msg(char *arg, int version, int current_stdout)
{
  if (version == 1)
    {
      my_putstr(current_stdout, arg);
      my_putstr(current_stdout, ": shell built-in command.\n");
      return (0);
    }
  else
    {
      my_putstr(current_stdout, arg);
      my_putstr(current_stdout, ": Command not found.\n");
      return (1);
    }
  return (0);
}

int	btin_which_validate(char **args, int current_stdout)
{
  if (args == NULL || array_len(args) < 2)
    {
      my_putstr(current_stdout, "which: Too few arguments.\n");
      return (1);
    }
  return (0);
}
