/*
** string.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 01:33:00 2017 Jérémy Sid Idris
** Last update Tue Jan 17 01:33:00 2017 Jérémy Sid Idris
*/

#ifndef STRING_H_
# define STRING_H_

int	len(char *);
int	my_strcmp(char *, char *);
char	*my_strdup(char *);
int	count_words(char *, char);
int	word_len(char *, char);
char	**my_str_to_wordtab(char *, char);
void	begin_new_word_in_tab(char **, int *, int *);
int	is_alphanum(char *);
int	is_separator(char);
int	is_quote(char);
void	epur_new_space(char *, int *, int *);
char	*end_epured_string(char *, int);
void	init_epur_str(int *, int *, int *);
char	*epur_str(char *);

#endif /* !STRING_H_ */
