/*
** keys.c for action_key in /home/yoann/Documents/2017/42SH/keys_handling
**
** Made by Yoann Sarkissian
** Login   <yoann.sarkissian@epitech.eu>
**
** Started on  Tue Apr 18 14:04:20 2017 Yoann Sarkissian
** Last update Thu Apr 27 18:27:55 2017 Yoann
*/

#include <string.h>
#include "input.h"

/*
** Move the cursor on the left
** @param line (the structure)
*/
void	crs_left(t_input *line)
{
  if (line->pos <= 0)
    return ;
  action("le");
  line->pos--;
}

/*
** Move the cursor on the right
** @param line (the structure)
*/
void	crs_right(t_input *line)
{
  if (line->pos >= line->len)
    return ;
  action("nd");
  line->pos++;
}

/*
** Delete character on the screen
** @param line (the structure)
*/
void	delete_print_char(t_input *line)
{
  int	i;

  i = line->pos;
  if (line->pos != 0 && line->len != 0)
    {
      action("le");
      action("dc");
      while (i <= line->len)
	{
	  line->buffer[i - 1] = line->buffer[i];
	  i++;
	}
      line->len--;
      line->pos--;
    }
}

/*
** Delete all character on the line
** @param line (the structure)
*/
void	rm_line(t_input *line)
{
  if (line->pos != 0)
    {
      while (line->pos > 0)
	delete_print_char(line);
      line->len = 0;
    }
  memset(line->buffer, 0, 1024);
}

void	home_key(t_input *line)
{
  while (line->pos > 0)
    crs_left(line);
}

void	end_key(t_input *line)
{
  while (line->pos < line->len)
    crs_right(line);
}
