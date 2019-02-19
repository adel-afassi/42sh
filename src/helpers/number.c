/*
** number.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 07:15:50 2017 Jérémy Sid Idris
** Last update Tue Jan 17 07:15:50 2017 Jérémy Sid Idris
*/

#include "helpers/number.h"

int	is_num(char *str)
{
  int	in_num;

  in_num = 0;
  while (*str != 0)
    {
      if (!(*str >= '0' && *str <= '9'))
	return (in_num);
      in_num = 1;
      str = str + 1;
    }
  return (2);
}

int	my_getnbr(char *str)
{
  int	number;

  number = 0;
  while (*str != 0)
    {
      number = number * 10;
      number = number + (*str - '0');
      str = str + 1;
    }
  return (number);
}
