/*
** home.c for  in /home/youcef/delivery/PSU/42sh
** 
** Made by youcef chergui
** Login   <youcef.chergui@epitech.net>
** 
** Started on  Tue Apr 11 02:21:43 2017 youcef chergui
** Last update Tue Apr 11 04:28:05 2017 youcef chergui
*/

#include <stdlib.h>
#include <string.h>
#include "helpers/string.h"
#include "helpers/memory.h"
#include "42sh.h"
#include "env.h"
#include "home.h"

char	*get_filepath_at_home(char *filename, t_list *env)
{
  char	*home;
  char	*path;

  if ((home = get_env_value("HOME", env)) == NULL)
    return (NULL);
  path = jmalloc(sizeof(char) * (len(home) + len(filename) + 2), ALLOC);
  strcpy(path, home);
  strcat(path, "/");
  strcat(path, filename);
  return (path);
}
