/*
** path.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 05:20:24 2017 Jérémy Sid Idris
** Last update Mon May  1 20:09:43 2017 adel
*/

#include <stdlib.h>
#include "helpers/memory.h"
#include "helpers/array.h"
#include "helpers/string.h"
#include "helpers/file.h"
#include "env.h"
#include "42sh.h"
#include "path.h"

char		*find_realpath(char *arg, t_list *env)
{
  int		i;
  char		*try_path;
  char		*path_value;
  char		**paths;

  i = 0;
  if (is_already_path(arg))
    return (arg);
  path_value = get_env_value("PATH", env);
  if (path_value == NULL)
    path_value = DEFAULT_PATH_VALUE;
  paths = my_str_to_wordtab(path_value, ':');
  while (i < array_len(paths))
    {
      try_path = make_path(arg, paths[i]);
      if (check_file_exist(try_path))
	return (try_path);
      jfree(try_path);
      i = i + 1;
    }
  return (NULL);
}

char		*find_realpath_static(char *arg, t_list *env)
{
  static int	i = 0;
  char		*try_path;
  char		*path_value;
  char		**paths;

  path_value = get_env_value("PATH", env);
  if (path_value == NULL)
    path_value = DEFAULT_PATH_VALUE;
  paths = my_str_to_wordtab(path_value, ':');
  while (i < array_len(paths))
    {
      try_path = make_path(arg, paths[i]);
      if (check_file_exist(try_path))
	{
	  i = i + 1;
	  return (try_path);
	}
      jfree(try_path);
      i = i + 1;
    }
  i = 0;
  return (NULL);
}

int		is_already_path(char *arg)
{
  while (*arg != 0)
    {
      if (*arg == '/')
	return (1);
      arg = arg + 1;
    }
  return (0);
}

char		*make_path(char *filename, char *path)
{
  int		i;
  char		*final_path;
  int		size;

  i = 0;
  size = len(filename) + len(path) + 5;
  final_path = jmalloc(sizeof(char) * size, ALLOC);
  while (*path != 0)
    {
      final_path[i] = *path;
      path = path + 1;
      i = i + 1;
    }
  final_path[i] = '/';
  i = i + 1;
  while (*filename != 0)
    {
      final_path[i] = *filename;
      filename = filename + 1;
      i = i + 1;
    }
  final_path[i] = '\0';
  return (final_path);
}
