/*
** btin_history.c for  in /home/youcef/delivery/PSU/42sh
** 
** Made by youcef chergui
** Login   <youcef.chergui@epitech.net>
** 
** Started on  Tue Apr 11 03:49:49 2017 youcef chergui
** Last update Tue Apr 11 05:42:06 2017 youcef chergui
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <stdio.h>
#include "helpers/output.h"
#include "helpers/array.h"
#include "helpers/number.h"
#include "helpers/string.h"
#include "utils/get_next_line.h"
#include "date.h"
#include "home.h"
#include "history.h"
#include "builtins/btin_history.h"

int	btin_history(int current_stdout, char **args, t_list **env)
{
  int	fd;
  char	*buffer;
  char	*path;
  char	**history;

  if (array_len(args) == 2)
    if (my_strcmp("-c", args[1]) == 0)
      return (clear_history(*env));
  if (((path = get_filepath_at_home(".42sh_history", *env)) == NULL) ||
      ((fd = open(path, O_RDONLY)) == -1))
    return (1);
  while ((buffer = get_next_line(fd)) != NULL)
    {
      if ((history = my_str_to_wordtab(buffer, ';')) == NULL)
	return (1);
      if ((print_history(history, current_stdout)) == 1)
	return (1);
    }
  close(fd);
  return (0);
}

int	print_history(char **history, int current_stdout)
{
  char	*date;
  char	*str;

  if ((date = convert_timestamp_to_date(my_getnbr(history[1]))) == NULL)
    return (1);
  my_putstr(current_stdout, "\t");
  my_putstr(current_stdout, history[0]);
  my_putstr(current_stdout, "\t");
  my_putstr(current_stdout, date);
  my_putstr(current_stdout, "\t");
  if ((str = wordtab_to_str(&history[2], ';')) == NULL)
    return (1);
  my_putstr(current_stdout, str);
  my_putstr(current_stdout, "\n");
  return (0);
}
