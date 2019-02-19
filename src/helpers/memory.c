/*
** memory.c for 42sh in /home/jeremy/Desktop/42sh/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Mon Apr 17 20:45:10 2017 Jérémy Sid Idris
** Last update Mon Apr 17 20:45:10 2017 Jérémy Sid Idris
*/

#include <stdio.h>
#include <stdlib.h>
#include "helpers/output.h"
#include "42sh.h"
#include "helpers/memory.h"

static t_memory	*memory_list = NULL;

void		*jmalloc(size_t size, int type)
{
  t_memory	*current_memory;
  void		*malloced;

  if ((malloced = malloc(size)) == NULL ||
      (current_memory = malloc(sizeof(t_memory))) == NULL)
    {
      print_error("Critical error : malloc failed, force exiting, sorry.\n");
      exit(84);
    }
  current_memory->pointer = malloced;
  current_memory->type = type;
  current_memory->next = memory_list;
  memory_list = current_memory;
  return (malloced);
}

void		jfree(void *ptr)
{
  t_memory	*current_tmp;
  t_memory	*old_tmp;

  if (ptr == NULL)
    return ;
  current_tmp = memory_list;
  old_tmp = NULL;
  while (current_tmp != NULL)
    {
      if (current_tmp->pointer == ptr)
	{
	  if (old_tmp == NULL)
	    memory_list = current_tmp->next;
	  else
	    old_tmp->next = current_tmp->next;
	  free(ptr);
	  free(current_tmp);
	  return ;
	}
      old_tmp = current_tmp;
      current_tmp = current_tmp->next;
    }
}

void		jfree_remaining(int type)
{
  t_memory	*current_tmp;
  t_memory	*old_tmp;
  t_memory	*next_tmp;

  current_tmp = memory_list;
  old_tmp = NULL;
  while (current_tmp != NULL)
    {
      if (current_tmp->type <= type)
	{
	  next_tmp = current_tmp->next;
	  if (old_tmp == NULL)
	    memory_list = current_tmp->next;
	  else
	    old_tmp->next = current_tmp->next;
	  free(current_tmp->pointer);
	  free(current_tmp);
	  current_tmp = next_tmp;
	  continue;
	}
      old_tmp = current_tmp;
      current_tmp = current_tmp->next;
    }
}
