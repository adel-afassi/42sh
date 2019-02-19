/*
** array.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 02:01:35 2017 Jérémy Sid Idris
** Last update Tue Jan 17 02:01:35 2017 Jérémy Sid Idris
*/

#ifndef ARRAY_H_
# define ARRAY_H_

int	array_len(char **);
int	exist_in_string_array(char, char *);
void	free_str_to_wordtab(char **);
char	*wordtab_to_str_make_string(char **, int *);
char	*wordtab_to_str(char **, char);

#endif /* !ARRAY_H_ */
