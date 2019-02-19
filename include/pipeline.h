/*
** pipeline.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Fri Apr  7 04:58:57 2017 Jérémy Sid Idris
** Last update Fri Apr  7 04:58:57 2017 Jérémy Sid Idris
*/

#ifndef PIPELINE_H_
# define PIPELINE_H_

# include "42sh.h"

int	pipeline_tokens(t_token *, t_list **);
void	handle_piped_process(t_token *, t_list **, int pipe[2], int *);
void	handle_end_pipe(t_token *, t_list **, int, int);
void	handle_pipeline_wait(t_token *);
int	get_pipeline_status_code(t_token *);

#endif /* !PIPELINE_H_ */
