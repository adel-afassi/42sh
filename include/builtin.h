/*
** builtin.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 03:51:22 2017 Jérémy Sid Idris
** Last update Mon Apr 10 22:55:58 2017 youcef chergui
*/

#ifndef BUILTIN_H_
# define BUILTIN_H_

int	is_builtin(char *);
int	exec_builtin(int, char **, t_list **);
int	list_builtins(int);

#endif /* !BUILTIN_H_ */
