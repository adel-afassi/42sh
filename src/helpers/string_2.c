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
#include "42sh.h"
#include "helpers/memory.h"
#include "helpers/string.h"

char	**my_str_to_wordtab(char *str, char sep)
{
  char	**result;
  int	i_word;
  int	i_letter;

  i_word = 0;
  i_letter = 0;
  result = jmalloc(sizeof(char *) * count_words(str, sep) + 10, ALLOC);
  result[i_word] = jmalloc(sizeof(char) * word_len(str, sep) + 1, ALLOC);
  while (*str != '\0')
    {
      if (*str == sep)
	{
	  begin_new_word_in_tab(result, &i_word, &i_letter);
	  result[i_word] = jmalloc(word_len(str + 1, sep) + 1, ALLOC);
	}
      else
	{
	  result[i_word][i_letter] = *str;
	  i_letter = i_letter + 1;
	}
      str = str + 1;
    }
  result[i_word][i_letter] = '\0';
  result[i_word + 1] = NULL;
  return (result);
}

void	begin_new_word_in_tab(char **result, int *i_word, int *i_letter)
{
  result[*i_word][*i_letter] = '\0';
  *i_word = *i_word + 1;
  *i_letter = 0;
}

int	is_alphanum(char *str)
{
  while (*str != 0)
    {
      if (!((*str >= 'A' && *str <= 'Z') ||
	  (*str >= 'a' && *str <= 'z') ||
	  (*str >= '0' && *str <= '9')))
	return (0);
      str = str + 1;
    }
  return (1);
}

int	is_separator(char c)
{
  if (c == '\t' || c == ' ')
    return (1);
  return (0);
}
