/*
** command.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Apr  5 21:48:10 2017 Jérémy Sid Idris
** Last update Wed Apr  5 21:48:10 2017 Jérémy Sid Idris
*/

#include <stdio.h>
#include <stdlib.h>
#include "helpers/string.h"
#include "helpers/memory.h"
#include "42sh.h"
#include "command.h"

/*
** Make an array of commands by parsing a line
** @param line (a line containing multiples commands)
** @return commands (an array of t_command pointers or NULL if error)
*/
t_command	**make_commands(char *line)
{
  t_command	**cmds;
  int		commands_amount;
  int		i;
  int		last_type;

  i = 0;
  last_type = COMMAND_REGULAR;
  commands_amount = count_commands_in_line(line);
  cmds = jmalloc(sizeof(t_command *) * (commands_amount + 1), LINE_ALLOC);
  while (i < commands_amount)
    {
      cmds[i] = jmalloc(sizeof(t_command), LINE_ALLOC);
      cmds[i]->type = last_type;
      cmds[i]->data =
	      epur_str(get_next_command_in_line(&line, &last_type));
      if ((cmds[i]->type == COMMAND_AND || cmds[i]->type == COMMAND_OR)
	  && my_strcmp(cmds[i]->data, "") == 0)
	return (NULL);
      cmds[i]->status_code = 0;
      i = i + 1;
    }
  cmds[i] = NULL;
  return (cmds);
}

/*
** Get next command in line and modify line by adding NULL char after command
** @param line (pointer of a line containing multiples commands)
** @param type (pointer of the next type of command modified after find sep)
** @return command (the found command null terminated)
*/
char	*get_next_command_in_line(char **line, int *type)
{
  int	i;
  char	*command;

  i = 0;
  command = *line;
  while (command[i] != 0)
    {
      if (get_command_separator_type(&command[i]) != -1)
	{
	  *type = get_command_separator_type(&command[i]);
	  command[i] = '\0';
	  *line = &command[i +
		  (*type == COMMAND_OR || *type == COMMAND_AND ? 2 : 1)];
	  return (command);
	}
      i = i + 1;
    }
  *type = -1;
  return (command);
}

/*
** Count the number of commands founds in line
** @param line (a line containing multiples commands)
** @return amount (the amount of commands in line)
*/
int	count_commands_in_line(char *line)
{
  int	amount;
  int	i;

  amount = 1;
  i = 0;
  while (line[i] != 0)
    {
      if (get_command_separator_type(&line[i]) != -1)
	{
	  amount = amount + 1;
	  if (get_command_separator_type(&line[i]) == COMMAND_OR ||
	      get_command_separator_type(&line[i]) == COMMAND_AND)
	    i = i + 1;
	}
      i = i + 1;
    }
  return (amount);
}

/*
** Get separator type (if found) in a string
** @param str (a string)
** @return type (COMMAND_AND/COMMAND_OR/COMMAND_REGULAR or -1 if not sep)
*/
int	get_command_separator_type(char *str)
{
  if (len(str) > 1)
    {
      if (str[0] == '&' && str[1] == '&')
	return (COMMAND_AND);
      else if (str[0] == '|' && str[1] == '|')
	return (COMMAND_OR);
    }
  if (str[0] == ';')
    return (COMMAND_REGULAR);
  return (-1);
}
