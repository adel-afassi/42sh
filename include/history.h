/*
** builtin.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 03:51:22 2017 Jérémy Sid Idris
** Last update Tue Apr 11 05:39:46 2017 youcef chergui
*/

#ifndef HISTORY_H_
# define HISTORY_H_

int	save_history(char *, t_list *);
int	clear_history(t_list *);
int	get_next_id();

#endif /* !HISTORY_H_ */
