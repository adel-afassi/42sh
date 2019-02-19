/*
** env.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 04:34:07 2017 Jérémy Sid Idris
** Last update Tue Jan 17 04:34:07 2017 Jérémy Sid Idris
*/

#ifndef ENV_H_
# define ENV_H_

# include "42sh.h"

char	*get_env_value(char *name, t_list *env);
void	update_env_value(char *name, char *value, t_list *env);
void	remove_env_value(char *name, t_list **env);
int	is_corresponding_key(char *key, char *str, int *begin_value);
char	*format_env_entry(char **args);

#endif /* !ENV_H_ */
