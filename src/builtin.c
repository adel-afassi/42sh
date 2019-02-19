/*
** builtin.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 03:39:59 2017 Jérémy Sid Idris
** Last update Mon May  1 16:33:48 2017 adel
*/

#include <stdlib.h>
#include "builtins/btin_cd.h"
#include "builtins/btin_setenv.h"
#include "builtins/btin_env.h"
#include "builtins/btin_unsetenv.h"
#include "builtins/btin_exit.h"
#include "builtins/btin_which.h"
#include "builtins/btin_repeat.h"
#include "builtins/btin_where.h"
#include "builtins/btin_echo.h"
#include "builtins/btin_kill.h"
#include "builtins/btin_history.h"
#include "builtins/btin_termname.h"
#include "helpers/string.h"
#include "helpers/output.h"
#include "42sh.h"
#include "builtin.h"

static t_builtin	g_builtins[] =
  {
    {btin_cd, "cd"},
    {btin_which, "which"},
    {btin_repeat, "repeat"},
    {btin_where, "where"},
    {btin_env, "env"},
    {btin_setenv, "setenv"},
    {btin_unsetenv, "unsetenv"},
    {btin_exit, "exit"},
    {btin_echo, "echo"},
    {btin_history, "history"},
    {btin_termname, "termname"},
    {btin_kill, "kill"},
    {NULL, NULL}
  };

int	list_builtins(int current_stdout)
{
  int	i;

  i = 0;
  while (g_builtins[i].command != NULL)
    {
      my_putstr(current_stdout, g_builtins[i].command);
      my_putstr(current_stdout, "\t\t");
      if ((i % 9) == 0 && i != 0)
	my_putstr(current_stdout, "\n");
      i = i + 1;
    }
  if ((i % 10) != 0)
    my_putstr(current_stdout, "\n");
  return (0);
}
int	is_builtin(char *arg)
{
  int	i;

  i = 0;
  while (g_builtins[i].command != NULL)
    {
      if (my_strcmp(arg, g_builtins[i].command) == 0)
	return (1);
      else if (my_strcmp(arg, "builtins") == 0)
	return (1);
      i = i + 1;
    }
  return (0);
}

int	exec_builtin(int current_stdout, char **args, t_list **env)
{
  char	*name;
  int	i;

  i = 0;
  name = args[0];
  while (g_builtins[i].command != NULL)
    {
      if (my_strcmp(name, g_builtins[i].command) == 0)
	{
	  return (g_builtins[i].handle(current_stdout, args, env));
	}
      else if (my_strcmp(name, "builtins") == 0)
	{
	  return (list_builtins(current_stdout));
	}
      i = i + 1;
    }
  return (1);
}
