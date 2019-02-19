/*
** write_car.c for write_car in /home/yoann/Documents/2017/42SH/keys_handling
**
** Made by Yoann Sarkissian
** Login   <yoann.sarkissian@epitech.eu>
**
** Started on  Thu Apr 20 17:44:50 2017 Yoann Sarkissian
** Last update Thu Apr 27 20:39:34 2017 Yoann
*/

#include <string.h>
#include <unistd.h>
#include "input.h"

/*
** Insert a character in the buffer
** @param line (the structure)
** @param c (the caracter to insert)
*/
void	insert_char(t_input *line, char *buf, int buf_size)
{
  int	i;
  int	pos;

  i = line->len - 1;
  pos = line->pos;
  line->buffer[i + buf_size + 1] = 0;
  while (i >= line->pos)
    {
      line->buffer[i + buf_size] = line->buffer[i];
      i--;
    }
  i = 0;
  while (buf_size > 0)
    {
      line->buffer[pos] = buf[i];
      pos++;
      i++;
      buf_size--;
    }
}

/*
** Add character on the cursor of the line
** @param line (the structure)
** @param buf (the buffer of the read)
*/
void	write_char(t_input *line, char *buf, int buf_size)
{
  action("im");
  if (buf[0] != 27)
    {
      write(1, buf, buf_size);
      if (line->pos == line->len)
	strncat(line->buffer, buf, buf_size);
      else if (line->pos < line->len)
	insert_char(line, buf, buf_size);
      line->pos = line->pos + buf_size;
      line->len = line->len + buf_size;
    }
  action("ei");
}
