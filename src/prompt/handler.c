/*
** prompt.c for key_history in /home/yoann.sarkissian/42SH/keys_handling
**
** Made by Yoann Sarkissian
** Login   <yoann.sarkissian@epitech.net>
**
** Started on  Sun Apr 23 15:59:10 2017 Yoann Sarkissian
** Last update Thu Apr 27 17:50:02 2017 Yoann
*/

#include <string.h>
#include <stdlib.h>
#include "helpers/string.h"
#include "helpers/output.h"
#include "input.h"

/*
** Catch all the line
** @param line (the structure)
** @return ret (the line)
*/
char	*get_buffer(t_input *line)
{
  char	*ret;

  ret = strdup(line->buffer);
  return (ret);
}

/*
** Replace the line per another
** @param line (the structure)
** @param str (the another line)
*/
void	set_buffer(t_input *line, char *str)
{
  rm_line(line);
  strcpy(line->buffer, str);
  line->len = len(str);
  line->pos = len(str);
  my_putstr(1, line->buffer);
}

/*
** Add a string at the end of the line
** @param line (the structure)
** @param str (the string to add)
*/
void	append_buffer(t_input *line, char *str)
{
  char	*tmp;

  tmp = malloc(sizeof(char) * 1024);
  strcpy(tmp, line->buffer);
  strcat(tmp, str);
  rm_line(line);
  strcpy(line->buffer, tmp);
  line->len = len(line->buffer);
  line->pos = len(line->buffer);
  my_putstr(1, line->buffer);
}
