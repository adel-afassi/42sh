/*
** btin_setenv.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src/builtins
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Thu Jan 19 14:31:41 2017 Jérémy Sid Idris
** Last update Thu Jan 19 14:31:41 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "helpers/string.h"
#include "helpers/list.h"
#include "helpers/output.h"
#include "helpers/array.h"
#include "env.h"
#include "42sh.h"
#include "builtins/btin_setenv.h"

int	btin_setenv(int current_stdout, char **args, t_list **env)
{
  char	*data;

  if (array_len(args) == 1)
    {
      my_putlist(current_stdout, *env);
      return (0);
    }
  else if (array_len(args) > 3)
    {
      print_error("setenv: Too many arguments.\n");
      return (1);
    }
  if (validate_env_key(args[1]) == 0)
    return (1);
  data = format_env_entry(args + 1);
  if (get_env_value(args[1], *env) == NULL)
   put_in_list(env, data, 2);
  else
    update_env_value(args[1], data, *env);
  return (0);
}

int	validate_env_key(char *key)
{
  if (!((key[0] >= 'A' && key[0] <= 'Z') || (key[0] >= 'a' && key[0] <= 'z')))
    {
      print_error("setenv: Variable name must begin with a letter.\n");
      return (0);
    }
  if (is_alphanum(key) == 0)
    {
      print_error("setenv: Variable name must contain"
		  " alphanumeric characters.\n");
      return (0);
    }
  return (1);
}
