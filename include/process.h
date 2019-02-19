/*
** process.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Fri Apr  7 04:54:44 2017 Jérémy Sid Idris
** Last update Fri Apr  7 04:54:44 2017 Jérémy Sid Idris
*/

#ifndef PROCESS_H_
# define PROCESS_H_

# include "42sh.h"

int	spawn_pipe_process(int, int pipe[2], char **, t_list *);
int	spawn_end_pipe_process(int, int, char **, t_list *);
void	dup_process_fd(int, int);

#endif /* !PROCESS_H_ */
