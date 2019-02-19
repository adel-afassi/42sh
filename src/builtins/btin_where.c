/*
** btin_where.c for  in /home/adel/delivery/42sh
** 
** Made by adel
** Login   <adel.afassi@epitech.eu>
** 
** Started on  Sun Apr 30 19:46:35 2017 adel
** Last update Mon May  1 20:06:25 2017 adel
*/

#include <stdlib.h>
#include "builtins/btin_where.h"
#include "helpers/output.h"
#include "helpers/array.h"
#include "builtin.h"
#include "binary.h"
#include "path.h"

/*
** builtin where
** @param current_stdout (int containing the sdtout for the function my_putstr)
** @param args (char ** containing the command and his arguments)
** @param env (a linked list pointer containing the env)
** @return code (return int containing the last status function or 1 if error)
*/
int	btin_where(int current_stdout, char **args, t_list **env)
{
  int	i;
  int	code;
  int	error;

  i = 1;
  code = 0;
  if (where_msg(args, NULL, current_stdout, -1))
    return (1);
  while (args[i] != NULL)
    {
      error = analysis_builtins(args[i], env, current_stdout);
      if (error != 0)
	code = 1;
      i = i + 1;
    }
  return (code);
}

int	analysis_builtins(char *args, t_list **env, int current_stdout)
{
  int	code;
  int	error;

  code = 0;
  error = 0;
  if (where_error_handling(args))
    {
      code = where_msg(NULL, args, current_stdout, 2);
      return (1);
    }
  if (is_builtin(args))
    {
      where_msg(NULL, args, current_stdout, 1);
      error = error + 1;
    }
  if (all_binary_path(args, env, current_stdout))
    error = error + 1;
  if (error == 0)
    code = 1;
  return (code);
}

int	all_binary_path(char *arg, t_list **env, int current_stdout)
{
  char	*path;

  if (is_binary(arg, *env))
    {
      while ((path = find_realpath_static(arg, *env)) != NULL)
	{
	  my_putstr(current_stdout, path);
	  my_putstr(current_stdout, "\n");
	}
      return (1);
    }
  return (0);
}

int	where_msg(char **args, char *arg, int stdout, int version)
{
  if (version == -1)
    {
      if (args == NULL || array_len(args) < 2)
	{
	  my_putstr(stdout, "where: Too few arguments.\n");
	  return (1);
	}
    }
  else if (version == 1)
    {
      my_putstr(stdout, arg);
      my_putstr(stdout, " is a shell built-in\n");
    }
  else
    {
      my_putstr(stdout, "where: / in command makes no sense\n");
      return (1);
    }
  return (0);
}

int	where_error_handling(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	return (1);
      i = i + 1;
    }
  return (0);
}
