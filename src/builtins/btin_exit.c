/*
** btin_exit.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src/builtins
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 07:27:42 2017 Jérémy Sid Idris
** Last update Tue Jan 17 07:27:42 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/output.h"
#include "helpers/number.h"
#include "helpers/string.h"
#include "helpers/array.h"
#include "42sh.h"
#include "builtins/btin_exit.h"

int	btin_exit(int current_stdout, char **args, t_list **env)
{
  (void)(current_stdout);
  (void)(env);
  if (array_len(args) > 2)
    {
      print_error("exit: Expression Syntax.\n");
      return (1);
    }
  else if (array_len(args) == 1)
    return (0);
  else
    return (handle_exit(args[1]));
}

int	handle_exit(char *status)
{
  if (is_num(status) == 0)
    {
      print_error("exit: Expression Syntax.\n");
      return (1);
    }
  else if (is_num(status) == 1)
    {
      print_error("exit: Badly formed number.\n");
      return (1);
    }
  else
    return (my_getnbr(status));
  return (0);
}
