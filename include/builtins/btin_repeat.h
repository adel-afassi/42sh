/*
** btin_repeat.h for  in /home/adel/delivery/42sh
** 
** Made by adel
** Login   <adel.afassi@epitech.eu>
** 
** Started on  Mon May  1 16:01:56 2017 adel
** Last update Mon May  1 20:05:44 2017 adel
*/

#ifndef BTIN_REPEAT_H_
# define BTIN_REPEAT_H_

# include "42sh.h"

int	btin_repeat(int , char **, t_list **);
int	btin_repeat_validate(char **);
char	*get_the_command(char *);
int	repeat_error_handling(char **, int);

#endif /* !BTIN_REPEAT_H_ */
