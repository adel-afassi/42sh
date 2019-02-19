/*
** pipeline.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Fri Apr  7 04:55:49 2017 Jérémy Sid Idris
** Last update Fri Apr  7 04:55:49 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include "helpers/string.h"
#include "helpers/output.h"
#include "binary.h"
#include "token.h"
#include "builtin.h"
#include "process.h"
#include "redirection.h"
#include "42sh.h"
#include "pipeline.h"

int		pipeline_tokens(t_token *token_list, t_list **env)
{
  int		current_stdin;
  int		end_stdout;
  int		fd_pipe[2];
  t_token	*tmp;

  tmp = token_list;
  current_stdin = get_redirection_input_fd(token_list);
  while (tmp->stdout_type == PIPE_REDIRECT)
    {
      pipe(fd_pipe);
      handle_piped_process(tmp, env, fd_pipe, &current_stdin);
      tmp = tmp->stdout_value;
    }
  if (tmp->status_code == 1 ||
      (end_stdout = get_redirection_output_fd(tmp)) == -1)
    return (1);
  handle_end_pipe(tmp, env, current_stdin, end_stdout);
  if (tmp->type == TYPE_BUILTIN && my_strcmp(tmp->args[0], "exit") != 0)
    return (tmp->status_code);
  handle_pipeline_wait(token_list);
  return (get_pipeline_status_code(token_list));
}

void	handle_piped_process(t_token *token, t_list **env,
			     int fd_pipe[2], int *current_stdin)
{
  if (token->status_code != 1)
    {
      if (is_builtin(token->args[0]))
	{
	  token->type = TYPE_BUILTIN;
	  token->status_code = exec_builtin(fd_pipe[1], &token->args[0], env);
	}
      else if (is_binary(token->args[0], *env))
	{
	  token->type = TYPE_BINARY;
	  token->pid = spawn_pipe_process(*current_stdin, fd_pipe,
					  token->args, *env);
	}
      else
	{
	  token->type = TYPE_UNKNOWN;
	  token->status_code = 1;
	  print_error(token->args[0]);
	  print_error(": Command not found.\n");
	}
    }
  close(fd_pipe[1]);
  if (*current_stdin != 0)
    close(*current_stdin);
  *current_stdin = fd_pipe[0];
}

void	handle_end_pipe(t_token *token, t_list **env,
			int current_stdin, int end_stdout)
{
  if (is_builtin(token->args[0]))
    {
      token->type = TYPE_BUILTIN;
      token->status_code = exec_builtin(end_stdout, &token->args[0], env);
    }
  else if (is_binary(token->args[0], *env))
    {
      token->type = TYPE_BINARY;
      token->pid = spawn_end_pipe_process(current_stdin, end_stdout,
					  token->args, *env);
    }
  else
    {
      token->type = TYPE_UNKNOWN;
      token->status_code = 1;
      print_error(token->args[0]);
      print_error(": Command not found.\n");
    }
  if (current_stdin != STDIN_FILENO)
    close(current_stdin);
  if (end_stdout != STDOUT_FILENO)
    close(end_stdout);
}

void		handle_pipeline_wait(t_token *token_list)
{
  t_token	*tmp;
  int		status_code;

  tmp = token_list;
  while (tmp != NULL)
    {
      if (tmp->type == TYPE_BINARY)
	{
	  if (tmp->pid == ERROR_PID || tmp->pid == UNKNOWN_PID)
	    tmp->status_code = 1;
	  else
	    {
	      waitpid(tmp->pid, &status_code, 0);
	      tmp->status_code = handle_child_ended(status_code);
	    }
	}
      if (tmp->stdout_type == PIPE_REDIRECT)
	tmp = tmp->stdout_value;
      else
	tmp = NULL;
    }
}

int		get_pipeline_status_code(t_token *token_list)
{
  t_token	*tmp;
  int		code;

  code = 0;
  tmp = token_list;
  while (tmp != NULL)
    {
      if (tmp->type == TYPE_BINARY)
	code = (tmp->status_code != 0 ? tmp->status_code : code);
      else if (tmp->type == TYPE_BUILTIN)
	code = (tmp->status_code != 0 || tmp->stdout_value == NULL ?
		tmp->status_code : code);
      else
	code = tmp->status_code;
      if (tmp->stdout_type == PIPE_REDIRECT)
	tmp = tmp->stdout_value;
      else
	tmp = NULL;
    }
  return (code);
}
