/*
** get_next_line.c for getnextline in /home/jeremy/Delivery/CPE_2016_getnextline
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Mon Jan  2 12:11:35 2017 Jérémy Sid Idris
** Last update Mon Jan  2 12:11:35 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include <unistd.h>
#include "helpers/memory.h"
#include "42sh.h"
#include "utils/get_next_line.h"

static char	buffer[READ_SIZE];
static int	last_fd = -1;

char	*get_next_line(const int fd)
{
  int	i_line;
  int	temp;
  int	i;
  int	in_line;
  char	*empty;
  char	*line;

  empty = jmalloc(sizeof(char), LINE_ALLOC);
  i = 0;
  empty[0] = '\0';
  temp = 0;
  i_line = 0;
  in_line = 0;
  if (last_fd != fd)
    buffer[0] = '\0';
  last_fd = fd;
  line = append_begin_buffer(&i, &i_line, &temp, in_line);
  if (temp == 1)
    return (line == NULL ? empty : line);
  line = read_data(fd, line, i_line);
  jfree(empty);
  return (line);
}

char	*read_data(int fd, char *line, int i_line)
{
  int	i;
  int	readed_size;

  while ((readed_size = read(fd, buffer, READ_SIZE)) != 0)
    {
      if ((line = my_alloc(line, readed_size, &i)) == NULL)
	return (NULL);
      i = 0;
      if (readed_size == -1)
	return (NULL);
      while (i < readed_size)
	{
	  if (buffer[i] == '\n')
	    {
	      line[i_line] = '\0';
	      buffer[readed_size] = '\0';
	      return (line);
	    }
	  line[i_line] = buffer[i];
	  i_line = i_line + 1;
	  i = i + 1;
	}
    }
  buffer[readed_size] = '\0';
  return (line);
}

char	*append_begin_buffer(int *i, int *i_line, int *temp, int in_line)
{
  char	*line;
  int	tmp;

  line = NULL;
  while (buffer[*i] != '\0')
    {
      if (buffer[*i] == '\n')
	{
	  if (in_line == 1)
	    {
	      cut_buffer(*i);
	      *temp = 1;
	      return (line);
	    }
	  in_line = 1;
	}
      else if (in_line == 1)
	{
	  line = my_alloc(line, 1, &tmp);
	  line[*i_line] = buffer[*i];
	  *i_line = *i_line + 1;
	}
      *i = *i + 1;
    }
  return (line);
}

void	cut_buffer(int i)
{
  char	*old_buffer;
  int	index;

  index = 0;
  old_buffer = jmalloc(sizeof(char) * READ_SIZE + 1, LINE_ALLOC);
  while (buffer[index] != '\0')
    {
      old_buffer[index] = buffer[index];
      index = index + 1;
    }
  old_buffer[index] = '\0';
  index = 0;
  while (old_buffer[i] != '\0')
    {
      buffer[index] = buffer[i];
      i = i + 1;
      index = index + 1;
    }
  buffer[index] = '\0';
  jfree(old_buffer);
}

char	*my_alloc(char *target, int size, int *i)
{
  int	old_size;
  char	*new_target;
  char	*tmp_target;

  old_size = 0;
  *i = 0;
  tmp_target = target;
  if (target == NULL)
    new_target = jmalloc(sizeof(char) * size + 1, LINE_ALLOC);
  else
    {
      while (target[old_size] != '\0')
	old_size = old_size + 1;
      new_target = jmalloc(sizeof(char) * size + old_size + 1, LINE_ALLOC);
      while (*target != '\0')
	{
	  new_target[*i] = *target;
	  *i = *i + 1;
	  target = target + 1;
	}
    }
  new_target[size + old_size] = '\0';
  jfree(tmp_target);
  return (new_target);
}
