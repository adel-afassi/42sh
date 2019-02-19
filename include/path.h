/*
** path.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 05:25:07 2017 Jérémy Sid Idris
** Last update Mon May  1 19:39:52 2017 adel
*/

#ifndef PATH_H_
# define PATH_H_

# include "42sh.h"

char	*find_realpath(char *arg, t_list *env);
char	*find_realpath_static(char *arg, t_list *env);
int	is_already_path(char *arg);
char	*make_path(char *filename, char *old_path);

#endif /* !PATH_H_ */
