/*
** btin_unsetenv.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src/builtins
**
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
**
** Started on  Thu Jan 19 17:49:43 2017 Jérémy Sid Idris
** Last update Thu Jan 19 17:49:43 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include <unistd.h>
#include "helpers/string.h"
#include "helpers/output.h"
#include "helpers/array.h"
#include "helpers/list.h"
#include "env.h"
#include "42sh.h"
#include "builtins/btin_unsetenv.h"

int	btin_unsetenv(int current_stdout, char **args, t_list **env)
{
  int	i;

  (void)(current_stdout);
  if (array_len(args) == 1)
    {
      print_error("unsetenv: Too few arguments.\n");
      return (1);
    }
  i = 1;
  while (i < array_len(args))
    {
      if (my_strcmp(args[i], "*") == 0)
	{
	  purge_list(env);
	  return (0);
	}
      if (get_env_value(args[i], *env) != NULL)
	remove_env_value(args[i], env);
      i = i + 1;
    }
  return (0);
}
