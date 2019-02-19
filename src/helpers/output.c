/*
** output.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Nov 29 23:37:46 2016 Jérémy Sid Idris
** Last update Tue Nov 29 23:37:46 2016 Jérémy Sid Idris
*/

#include <stdlib.h>
#include <unistd.h>
#include "helpers/string.h"
#include "helpers/memory.h"
#include "42sh.h"
#include "helpers/output.h"

int	print_error(char *str)
{
  write(2, str, len(str));
  return (1);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(int current_stdout, char *str)
{
  write(current_stdout, str, len(str));
}

void	my_putlist(int current_stdout, t_list *elem)
{
  while (elem != NULL)
    {
      my_putstr(current_stdout, elem->content);
      my_putstr(current_stdout, "\n");
      elem = elem->next;
    }
}

void	fatal_exit(char *message)
{
  print_error(message);
  jfree_remaining(ALLOC);
  exit(84);
}
