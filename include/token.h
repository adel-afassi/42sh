/*
** token.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Apr  5 22:23:10 2017 Jérémy Sid Idris
** Last update Wed Apr  5 22:23:10 2017 Jérémy Sid Idris
*/

#ifndef TOKEN_H_
# define TOKEN_H_

# include "42sh.h"

t_token	*add_token(t_token *, char **);
char	**parse_token_redirect(t_token *, char **);
void	permut_arg(int, int *, char **, char **);
int	is_null_token(t_token *);
void	add_redirection(t_token *, int, char *, int);

#endif /* !TOKEN_H_ */
