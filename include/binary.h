/*
** binary.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 04:18:25 2017 Jérémy Sid Idris
** Last update Tue Jan 17 04:18:25 2017 Jérémy Sid Idris
*/

#ifndef BINARY_H_
# define BINARY_H_

# include "42sh.h"

int	is_binary(char *arg, t_list *env);
int	try_to_run_binary_validation(char *file);
int	handle_child_ended(int);

#endif /* !BINARY_H_ */
