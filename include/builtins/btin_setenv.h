/*
** btin_setenv.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include/builtins
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Thu Jan 19 15:18:31 2017 Jérémy Sid Idris
** Last update Thu Jan 19 15:18:31 2017 Jérémy Sid Idris
*/

#ifndef BTIN_SETENV_H_
# define BTIN_SETENV_H_

# include "42sh.h"

int	btin_setenv(int, char **, t_list **);
int	validate_env_key(char *);

#endif /* !BTIN_SETENV_H_ */
