/*
** array.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 01:59:22 2017 Jérémy Sid Idris
** Last update Tue Jan 17 01:59:22 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/memory.h"
#include "helpers/string.h"
#include "42sh.h"
#include "helpers/array.h"

int	array_len(char **array)
{
  int	i;

  i = 0;
  while (array[i] != NULL)
    {
      i = i + 1;
    }
  return (i);
}

int	exist_in_string_array(char pattern, char *array)
{
  int	i;

  i = 0;
  while (array[i] != 0)
    {
      if (pattern == array[i])
	return (1);
      i = i + 1;
    }
  return (0);
}

void	free_str_to_wordtab(char **arr)
{
  int	i;

  i = 0;
  while (arr[i] != NULL)
    {
      jfree(arr[i]);
      i = i + 1;
    }
  jfree(arr);
}

char	*wordtab_to_str_make_string(char **array, int *i)
{
  char	*string;
  int	size;

  *i = 0;
  size = 0;
  while (array[*i] != NULL)
    {
      size = size + len(array[*i]) + 1;
      *i = *i + 1;
    }
  string = jmalloc(sizeof(char) * size + 1, ALLOC);
  *i = 0;
  return (string);
}

char	*wordtab_to_str(char **array, char separator)
{
  int	x;
  int	i;
  int	j;
  char	*result;

  result = wordtab_to_str_make_string(array, &i);
  x = 0;
  while (array[i] != NULL)
    {
      j = 0;
      while (array[i][j] != '\0')
	{
	  result[x] = array[i][j];
	  x = x + 1;
	  j = j + 1;
	}
      if (array[i + 1] != NULL)
	{
	  result[x] = separator;
	  x = x + 1;
	}
      i = i + 1;
    }
  result[x] = '\0';
  return (result);
}
