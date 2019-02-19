/*
** output.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 01:28:53 2017 Jérémy Sid Idris
** Last update Tue Jan 17 01:28:53 2017 Jérémy Sid Idris
*/

#ifndef OUTPUT_H_
# define OUTPUT_H_

# include "42sh.h"

int	print_error(char *);
void	my_putchar(char);
void	my_putstr(int, char *);
void	my_putlist(int, t_list *);
void	fatal_exit(char *);

#endif /* !OUTPUT_H_ */
