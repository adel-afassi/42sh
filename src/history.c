/*
** history.c for  in /home/youcef/delivery/PSU/42sh
** 
** Made by youcef chergui
** Login   <youcef.chergui@epitech.net>
** 
** Started on  Mon Apr 10 23:10:52 2017 youcef chergui
** Last update Tue Apr 11 05:42:46 2017 youcef chergui
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include "helpers/string.h"
#include "helpers/memory.h"
#include "helpers/output.h"
#include "utils/get_next_line.h"
#include "42sh.h"
#include "env.h"
#include "home.h"
#include "history.h"

static int  	g_fd = 0;
static int	g_id = -1;

int	get_next_id()
{
  if (g_id == -1)
    {
      g_id = 1;
      while (get_next_line(g_fd) != NULL)
	g_id = g_id + 1;
    }
  else
    g_id = g_id + 1;
  return (g_id);
}

int	clear_history(t_list *env)
{
  char	*path;

  close(g_fd);
  if ((path = get_filepath_at_home(".42sh_history", env)) == NULL)
    return (1);
  if ((g_fd = open(path, O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR |
		   S_IRGRP | S_IWGRP | S_IROTH)) == -1)
    return (1);
  g_id = 0;
  return (0);
}

int	save_history(char *line, t_list *env)
{
  char	*path;
  char	line_history[MAX_LINE_SIZE + TIMESTAMP_MAXSIZE + 1];
  int	timestamp;

  if (len(line) == 0)
    return (1);
  if ((path = get_filepath_at_home(".42sh_history", env)) == NULL)
    return (1);
  if ((g_fd == 0) && (g_fd = open(path, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR |
			      S_IRGRP | S_IWGRP | S_IROTH)) == -1)
    return (1);
  g_id = get_next_id();
  timestamp = time(NULL);
  sprintf(line_history, "%d;%d;%s\n", g_id, timestamp, line);
  write(g_fd, line_history, len(line_history));
  return (0);
}
