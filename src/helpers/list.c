/*
** list.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 01:54:29 2017 Jérémy Sid Idris
** Last update Tue Jan 17 01:54:29 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/memory.h"
#include "helpers/string.h"
#include "helpers/array.h"
#include "42sh.h"
#include "helpers/list.h"

void		put_in_list(t_list **list, char *content, int method)
{
  t_list	*tmp;
  t_list	*element;

  element = jmalloc(sizeof(t_list), ALLOC);
  element->content = content;
  method = (count_list(*list) == 0 ? 1 : method);
  if (method == 1)
    {
      element->next = *list;
      *list = element;
    }
  else
    {
      tmp = *list;
      element->next = NULL;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = element;
    }
}

int		count_list(t_list *begin)
{
  t_list	*tmp;
  int		count;

  count = 0;
  tmp = begin;
  while (tmp != 0)
    {
      count = count + 1;
      tmp = tmp->next;
    }
  return (count);
}

void		purge_list(t_list **list)
{
  t_list	*tmp;
  t_list	*tmp2;

  tmp = *list;
  tmp2 = NULL;
  while (tmp != NULL)
    {
      tmp2 = tmp;
      jfree(tmp->content);
      tmp = tmp->next;
      jfree(tmp2);
    }
  *list = NULL;
}

t_list		*import_list(char **array)
{
  t_list	*current_list;
  char		*buffer;
  int		i;

  i = array_len(array) - 1;
  current_list = NULL;
  while (i != -1)
    {
      buffer = my_strdup(array[i]);
      put_in_list(&current_list, buffer, 1);
      i = i - 1;
    }
  return (current_list);
}

char	**export_list(t_list *list)
{
  char	**result;
  int	i;

  i = 0;
  result = jmalloc(sizeof(char *) * (count_list(list) + 1), ALLOC);
  while (list != NULL)
    {
      result[i] = list->content;
      i = i + 1;
      list = list->next;
    }
  result[i] = NULL;
  return (result);
}
