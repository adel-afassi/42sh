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

int	len(char *str)
{
  int	count;

  count = 0;
  while (*str != 0)
    {
      count = count + 1;
      str = str + 1;
    }
  return (count);
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] == str2[i] && str1[i] != 0)
    i = i + 1;
  return (str1[i] - str2[i]);
}

char	*my_strdup(char *src)
{
  int	i;
  int	size;
  char	*result;

  i = 0;
  size = len(src);
  result = jmalloc(sizeof(char) * size + 1, ALLOC);
  while (i < size)
    {
      result[i] = src[i];
      i = i + 1;
    }
  result[i] = 0;
  return (result);
}

int	count_words(char *str, char separator)
{
  int	words;

  words = 1;
  while (*str != 0)
    {
      if (*str == separator)
	words = words + 1;
      str = str + 1;
    }
  return (words);
}

int	word_len(char *str, char separator)
{
  int	i;

  i = 0;
  while (*str != 0)
    {
      if (*str == separator)
	break ;
      i = i + 1;
      str = str + 1;
    }
  return (i);
}
