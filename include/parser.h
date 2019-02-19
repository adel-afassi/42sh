/*
** parser.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Apr  4 02:40:20 2017 Jérémy Sid Idris
** Last update Tue Apr  4 02:40:20 2017 Jérémy Sid Idris
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "42sh.h"

int	line_parser(char *, t_list **);
int	command_parser(char *, t_list **, char *);
int	get_line_code(char, int);

#endif /* !PARSER_H_ */
