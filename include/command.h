/*
** command.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 04:18:25 2017 Jérémy Sid Idris
** Last update Tue Jan 17 04:18:25 2017 Jérémy Sid Idris
*/

#ifndef COMMAND_H_
# define COMMAND_H_

# include "42sh.h"

t_command	**make_commands(char *);
char		*get_next_command_in_line(char **, int *);
int		count_commands_in_line(char *);
int		get_command_separator_type(char *);

#endif /* !COMMAND_H_ */
