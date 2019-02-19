/*
** btin_where.h for  in /home/adel/delivery/42sh
** 
** Made by adel
** Login   <adel.afassi@epitech.eu>
** 
** Started on  Sun Apr 30 20:00:24 2017 adel
** Last update Mon May  1 20:04:47 2017 adel
*/

#ifndef BTIN_WHERE_H_
# define BTIN_WHERE_H_

# include "42sh.h"

int	btin_where(int, char **, t_list **);
int	all_binary_path(char *, t_list **, int);
int	where_msg(char **, char *, int, int);
int	it_is_binary(char *, t_list **, int);
int	analysis_builtins(char *, t_list **, int);
int	where_error_handling(char *);

#endif /* !BTIN_WHERE_H_ */
