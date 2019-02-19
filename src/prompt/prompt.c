/*
** test.c for test in /home/yoann/Documents/2017/42SH
**
** Made by Yoann Sarkissian
** Login   <yoann.sarkissian@epitech.eu>
**
** Started on  Mon Apr 10 23:53:30 2017 Yoann Sarkissian
** Last update Thu Apr 27 20:38:53 2017 Yoann
*/

#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "helpers/string.h"
#include "helpers/output.h"
#include "input.h"

/*
** Do the action (cursor left, right etc.)
** @param seq (take the key sequence as parameter)
*/
void	action(char *seq)
{
  char	*tmp;

  if (seq == NULL || (tmp = tgetstr(seq, NULL)) == NULL)
    return ;
  my_putstr(1, tmp);
}

/*
** Initialise the structure t_input
** @param line (the structure)
*/
void	init_struct(t_input *line)
{
  memset(line->buffer, 0, 1024);
  line->len = 0;
  line->pos = 0;
}

/*
** Check the enter of the user on stdin
** @return return -1 if there is an error
*/
char	*interactive_get_next_line(t_input *line)
{
  char	buffer[5];
  int	buf_size;

  buf_size = 0;
  while (1)
    {
      buf_size = read(0, buffer, 5);
      //      printf("buffer[0] : %d, len : %d\n", buffer[0], b);
      if (buffer[0] == 27)
	buffer[1] = 79;
      // PROCHAINEMENT POINTEUR SUR FONCTION
      if (strncmp(buffer, tigetstr("kcub1"), 3) == 0)
	crs_left(line);
      else if (strncmp(buffer, tigetstr("kcuf1"), 3) == 0)
	  crs_right(line);
	else if (strncmp(buffer, tigetstr("kcuu1"), 3) == 0)
	    {
	      // JUSTE POUR TEST ;)
	      append_buffer(line, "tozz");
	    }
	  else if (strncmp(buffer, tigetstr("khome"), 3) == 0)
	      home_key(line);
	    else if (strncmp(buffer, tigetstr("kend"), 3) == 0)
		end_key(line);
	      else if (buffer[0] == 127)
		  delete_print_char(line);
		else if (buffer[0] == 10)
		    {
		      return (line->buffer);
		    }
		  else
		    write_char(line, buffer, buf_size);
    }
  return (0);
}
