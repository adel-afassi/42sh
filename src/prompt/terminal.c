/*
** terminal.c for main in /home/yoann/Documents/2017/42SH/keys_handling
**
** Made by Yoann Sarkissian
** Login   <yoann.sarkissian@epitech.eu>
**
** Started on  Mon Apr 17 00:37:57 2017 Yoann Sarkissian
** Last update Thu Apr 27 18:02:46 2017 Yoann
*/

#include <termios.h>
#include <stdlib.h>
#include <ncurses.h>
#include <term.h>
#include "input.h"

/*
** Set the terminal with non-blocking read
** @param term (the termios structure)
** @return return -1 if there is an error
*/
int	term_handling(struct termios *term)
{
  char	*name_term;

  if ((name_term = getenv("TERM")) == NULL)
    return (-1);
  if (tgetent(NULL, name_term) == -1)
    return (-1);
  if (tcgetattr(0, term) == -1)
    return (-1);
  term->c_lflag &= ~(ICANON | ECHO);
  term->c_cc[VMIN] = 1;
  term->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSADRAIN, term) == -1)
    return (-1);
  return (0);
}

/*
** Reset the terminal
** @param term (the termios structure)
** @return return -1 if there is an error
*/
int	reset_term(struct termios *term)
{
  if (tcgetattr(0, term) == -1)
    return (-1);
  term->c_lflag = (ICANON | ECHO);
  if (tcsetattr(0, 0, term) == -1)
    return (-1);
  return (0);
}
