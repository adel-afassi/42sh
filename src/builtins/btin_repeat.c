/*
** btin_repeat.c for  in /home/adel/delivery/42sh
** 
** Made by adel
** Login   <adel.afassi@epitech.eu>
** 
** Started on  Mon May  1 16:01:26 2017 adel
** Last update Mon May  1 20:06:06 2017 adel
*/

#include <stdlib.h>
#include "parser.h"
#include "helpers/array.h"
#include "helpers/number.h"
#include "helpers/output.h"
#include "helpers/memory.h"
#include "builtin.h"
#include "builtins/btin_repeat.h"

/*
** builtin repeat (repeat command during n times)
** @param current_stdout (int containing the sdtout for the function my_putstr)
** @param args (char ** containing the command and his arguments)
** @param env (linked list pointer containing the env)
** @return code (return int containing the last status function or 1 if error)
*/
int	btin_repeat(int current_stdout, char **args, t_list **env)
{
  int	i;
  int	repeat;
  int	code;
  char	*command;

  i = 0;
  code = 0;
  if (btin_repeat_validate(args))
    return (1);
  if (is_num(args[1]) != 2)
    return (repeat_error_handling(args, current_stdout));
  repeat = my_getnbr(args[1]);
  if ((command = wordtab_to_str(args, ' ')) == NULL)
    return (1);
  command = get_the_command(command);
  while (i < repeat)
    {
      code = line_parser(command, env);
      i = i + 1;
    }
  return (code);
}

char	*get_the_command(char *str)
{
  int	i;

  i = 0;
  while (*str != '\0')
    {
      if (*str == ' ')
	i = i + 1;
      if (i == 2)
	{
	  str = str + 1;
	  return (str);
	}
      str = str + 1;
    }
  return (str);
}

int	btin_repeat_validate(char **args)
{
  if (args == NULL || array_len(args) < 3)
    {
      print_error("repeat: Too few arguments.\n");
      return (1);
    }
  return (0);
}

int	repeat_error_handling(char ** args, int stdout)
{
  if (args[1][0] != '-' && (args[1][1] < '0' || args[1][1] > '9'))
    my_putstr(stdout, "repeat: Badly formed number.\n");
  else if (args[1][1] == '-')
    my_putstr(stdout, "repeat: Badly formed number.\n");
  return (1);
}
