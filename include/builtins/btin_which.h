/*
** btin_which.h for  in /home/adel/delivery/42sh
**
** Made by adel
** Login   <adel.afassi@epitech.eu>
**
** Started on  Wed Apr 12 16:58:01 2017 adel
** Last update Mon May  1 19:14:56 2017 adel
*/

#ifndef BTIN_WHICH_H_
# define BTIN_WHICH_H_

# include "42sh.h"

int	btin_which(int, char **, t_list **);
int	btin_which_validate(char **, int);
int	builtin_msg(char *, int, int);
int	it_is_binary(char *, t_list **, int);

#endif /* !BTIN_WHICH_H_ */
