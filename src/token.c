/*
** token.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Apr  5 21:48:10 2017 Jérémy Sid Idris
** Last update Wed Apr  5 21:48:10 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/string.h"
#include "helpers/array.h"
#include "helpers/memory.h"
#include "redirection.h"
#include "42sh.h"
#include "token.h"

t_token		*add_token(t_token *previous_token, char **args)
{
  t_token	*token;

  token = jmalloc(sizeof(t_token), LINE_ALLOC);
  token->stdin_type = NULL_REDIRECT;
  token->stdin_value = NULL;
  if (previous_token == NULL)
    {
      token->stdout_type = NULL_REDIRECT;
      token->stdout_value = NULL;
    }
  else
    {
      token->stdout_type = PIPE_REDIRECT;
      token->stdout_value = previous_token;
      if (previous_token->stdin_type != NULL_REDIRECT)
	catch_fatal_redirection_error(REDIRECT_AMBIGUOUS_INPUT);
      previous_token->stdin_type = PIPE_REDIRECT;
      previous_token->stdin_value = token;
    }
  token->pid = 0;
  token->type = TYPE_UNKNOWN;
  token->pid = UNKNOWN_PID;
  token->status_code = 0;
  token->args = parse_token_redirect(token, args);
  return (token);
}

char	**parse_token_redirect(t_token *token, char **old_args)
{
  char	**new_args;
  int	i;
  int	new_i;

  new_args = jmalloc(sizeof(char *) * (array_len(old_args) + 1), LINE_ALLOC);
  i = 0;
  new_i = 0;
  while (old_args[i] != NULL)
    {
      if (is_redirection_arg(old_args[i]) > 0)
	{
	  if (is_redirection_arg(old_args[i]) == 1 && old_args[i + 1] == NULL)
	    catch_fatal_redirection_error(REDIRECT_MISSING_NAME);
	  add_redirection(token, get_redirection_type(old_args[i]),
	      old_args[i + (is_redirection_arg(old_args[i]) == 1 ? 1 : 0)],
	      is_redirection_arg(old_args[i]));
	  i = i + (is_redirection_arg(old_args[i]) == 1 ? 1 : 0);
	}
      else
	permut_arg(i, &new_i, old_args, new_args);
      i = i + 1;
    }
  new_args[new_i] = NULL;
  return (new_args);
}

void	permut_arg(int i, int *new_i, char **old_args, char **new_args)
{
  new_args[*new_i] = old_args[i];
  *new_i = *new_i + 1;
}

int	is_null_token(t_token *token)
{
  char	**args;

  args = token->args;
  if (array_len(args) == 0 || (array_len(args) == 1 && len(args[0]) == 0))
    return (1);
  return (0);
}

void	add_redirection(t_token *token, int redirection,
			char *target, int type)
{
  if (type == 2)
    target = target + ((redirection % 10) == 0 ? 2 : 1);
  if (redirection == IN_ARROW || redirection == IN_DOUBLE_ARROW)
    {
      if (token->stdin_type != NULL_REDIRECT)
	catch_fatal_redirection_error(REDIRECT_AMBIGUOUS_INPUT);
      token->stdin_type = (redirection == IN_ARROW ? FILE_REDIRECT :
			                             FILE_ADVANCED_REDIRECT);
      token->stdin_value = target;
    }
  else if (redirection == OUT_ARROW || redirection == OUT_DOUBLE_ARROW)
    {
      if (token->stdout_type != NULL_REDIRECT)
	catch_fatal_redirection_error(REDIRECT_AMBIGUOUS_OUTPUT);
      token->stdout_type = (redirection == OUT_ARROW ? FILE_REDIRECT :
			                               FILE_ADVANCED_REDIRECT);
      token->stdout_value = target;
    }
}
