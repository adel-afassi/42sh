/*
** file.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 05:01:47 2017 Jérémy Sid Idris
** Last update Tue Jan 17 05:01:47 2017 Jérémy Sid Idris
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "helpers/file.h"

int		check_file_exist(char *path)
{
  struct stat	file;

  if (stat(path, &file) == 0)
    return (1);
  return (0);
}

int		can_exec_file(char *path)
{
  struct stat	file;

  if (access(path, F_OK) == -1)
    return (1);
  else if (access(path, X_OK) == -1)
    return (2);
  if (stat(path, &file) != 0)
    return (1);
  if (S_ISREG(file.st_mode) == 0)
    return (2);
  return (0);
}

int		can_open_dir(char *path)
{
  struct stat	dir;

  if (access(path, F_OK) == -1)
    return (1);
  if (stat(path, &dir) != 0)
    return (1);
  if (S_ISDIR(dir.st_mode) == 0)
    return (3);
  if (access(path, X_OK) == -1)
    return (2);
  return (0);
}
