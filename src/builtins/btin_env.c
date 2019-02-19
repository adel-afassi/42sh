/*
** btin_env.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src/builtins
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Jan 21 14:00:00 2017 Jérémy Sid Idris
** Last update Sat Jan 21 14:00:00 2017 Jérémy Sid Idris
*/

#include "helpers/output.h"
#include "42sh.h"
#include "builtins/btin_env.h"

int	btin_env(int current_stdout, char **args, t_list **env)
{
  (void)(args);
  my_putlist(current_stdout, *env);
  return (0);
}
