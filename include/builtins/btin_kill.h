/*
** btin_kill.h for  in /home/youcef/delivery/PSU/42sh
** 
** Made by youcef chergui
** Login   <youcef.chergui@epitech.net>
** 
** Started on  Tue Apr 11 15:09:32 2017 youcef chergui
** Last update Fri Apr 14 17:04:11 2017 youcef chergui
*/

#ifndef BTIN_KILL_H_
# define BTIN_KILL_H_

# include "42sh.h"

int	btin_kill(int, char **, t_list **);
int	check_signal(char **);
int	send_signals_to_process(char **, int);
void	print_kill_error(char *, int *, char *);
int	bad_arg_or_sig(char **, int *);

#endif /* !BTIN_KILL_H_ */
