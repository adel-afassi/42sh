/*
** list.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 02:02:13 2017 Jérémy Sid Idris
** Last update Tue Jan 17 02:02:13 2017 Jérémy Sid Idris
*/

#ifndef LIST_H_
# define LIST_H_

# include "42sh.h"

void	put_in_list(t_list **list, char *content, int method);
int	count_list(t_list *begin);
void	purge_list(t_list **list);
t_list	*import_list(char **array);
char	**export_list(t_list *list);

#endif /* !LIST_H_ */
