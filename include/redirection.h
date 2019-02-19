/*
** redirection.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Apr  8 19:46:34 2017 Jérémy Sid Idris
** Last update Sat Apr  8 19:46:34 2017 Jérémy Sid Idris
*/

#ifndef REDIRECTION_H_
# define REDIRECTION_H_

# include "42sh.h"

int	is_redirection_arg(char *);
int	get_redirection_type(char *);
void	catch_fatal_redirection_error(int);
int	get_redirection_input_fd(t_token *);
int	get_redirection_output_fd(t_token *);

#endif /* !REDIRECTION_H_ */
