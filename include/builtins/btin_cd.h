/*
** btin_cd.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include/builtins
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 07:07:58 2017 Jérémy Sid Idris
** Last update Tue Jan 17 07:07:58 2017 Jérémy Sid Idris
*/

#ifndef BTIN_CD_H_
# define BTIN_CD_H_

# include "42sh.h"

int	btin_cd(int, char **, t_list **);
int	throw_cd_error(char *, int);
char	*btin_cd_validate(char **, t_list **);
void	switch_directory(char *);

#endif /* !BTIN_CD_H_ */
