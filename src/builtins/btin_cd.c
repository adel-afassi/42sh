/*
** btin_cd.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src/builtins
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 06:55:10 2017 Jérémy Sid Idris
** Last update Tue Apr 11 17:02:53 2017 Yoann Sarkissian
*/

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include "helpers/memory.h"
#include "helpers/file.h"
#include "helpers/output.h"
#include "helpers/string.h"
#include "helpers/array.h"
#include "env.h"
#include "42sh.h"
#include "builtins/btin_cd.h"

int		btin_cd(int current_stdout, char **args, t_list **env)
{
  static char	*old_path = NULL;
  char		*path;
  int		status;

  (void)(current_stdout);
  if ((path = btin_cd_validate(args, env)) == NULL)
    return (1);
  if (my_strcmp(path, "-") == 0)
    path = (old_path == NULL ? "" : old_path);
  else if (my_strcmp(path, "--") == 0)
    {
      if ((path = get_env_value("HOME", *env)) == NULL)
	return (1);
    }
  old_path = jmalloc(sizeof(char) * PATH_MAX + 1, ALLOC);
  getcwd(old_path, PATH_MAX);
  if ((status = can_open_dir(path)) != 0)
    return (throw_cd_error(path, status));
  switch_directory(path);
  return (0);
}

int	throw_cd_error(char *path, int status)
{
  print_error(path);
  if (status == 1)
    print_error(": No such file or directory.\n");
  else if (status == 2)
    print_error(": Permission denied.\n");
  else if (status == 3)
    print_error(": Not a directory.\n");
  return (1);
}

char	*btin_cd_validate(char **args, t_list **env)
{
  char	*path;

  if (array_len(args) > 2)
    {
      print_error("cd: Too many arguments.\n");
      return (NULL);
    }
  else if (array_len(args) == 1)
    path = get_env_value("HOME", *env);
  else
    path = args[1];
  if (path == NULL)
    {
      print_error("cd: No home directory.\n");
      return (NULL);
    }
  return (path);
}

void	switch_directory(char *path)
{
  if (chdir(path) == -1)
    print_error("Unhandled chdir error :/");
}
