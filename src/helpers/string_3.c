/*
** string.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 01:27:12 2017 Jérémy Sid Idris
** Last update Tue Jan 17 01:27:12 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/memory.h"
#include "42sh.h"
#include "helpers/string.h"

int	is_quote(char c)
{
  if (c == ' ' || c == '\'')
    return (1);
  return (0);
}

void	epur_new_space(char *epured, int *i, int *in_space)
{
  epured[*i] = ' ';
  *i = *i + 1;
  *in_space = 1;
}

char	*end_epured_string(char *epured, int i)
{
  if (i > 0 && epured[i - 1] == ' ')
    epured[i - 1] = '\0';
  else
    epured[i] = '\0';
  return (epured);
}

void	init_epur_str(int *i, int *in_space, int *in_quote)
{
  *i = 0;
  *in_space = 1;
  *in_quote = 0;
}

char	*epur_str(char *str)
{
  int	i;
  int	in_quote;
  int	in_space;
  char	*epured;

  epured = jmalloc(sizeof(char) * len(str) + 1, ALLOC);
  init_epur_str(&i, &in_space, &in_quote);
  while (*str != 0)
    {
      if (!in_quote && is_separator(*str))
	{
	  if (in_space == 0)
	    epur_new_space(epured, &i, &in_space);
	}
      else
	{
	  if (is_quote(*str))
	    in_quote = (in_quote == 0 ? 1 : 0);
	  in_space = 0;
	  epured[i] = *str;
	  i = i + 1;
	}
      str = str + 1;
    }
  return (end_epured_string(epured, i));
}
