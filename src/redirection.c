/*
** redirection.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Apr  8 19:39:57 2017 Jérémy Sid Idris
** Last update Sat Apr  8 19:39:57 2017 Jérémy Sid Idris
*/

#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "helpers/memory.h"
#include "helpers/output.h"
#include "helpers/string.h"
#include "redirection.h"

int	is_redirection_arg(char *arg)
{
  if (len(arg) >= 2 && ((arg[0] == '>' && arg[1] == '>')
			|| (arg[0] == '<' && arg[1] == '<')))
    return (len(arg) == 2 ? 1 : 2);
  if (len(arg) >= 1 && (arg[0] == '>' || arg[0] == '<'))
    return (len(arg) == 1 ? 1 : 2);
  return (0);
}

int	get_redirection_type(char *arg)
{
  if (arg[0] == '<')
    {
      if (len(arg) > 1 && arg[1] == '<')
	return (IN_DOUBLE_ARROW);
      else
	return (IN_ARROW);
    }
  else
    {
      if (len(arg) > 1 && arg[1] == '>')
	return (OUT_DOUBLE_ARROW);
      else
	return (OUT_ARROW);
    }
}

void	catch_fatal_redirection_error(int type)
{
  if (type == REDIRECT_MISSING_NAME)
    print_error("Missing name for redirect.\n");
  else if (type == REDIRECT_AMBIGUOUS_INPUT)
    print_error("Ambiguous input redirect.\n");
  else if (type == REDIRECT_AMBIGUOUS_OUTPUT)
    print_error("Ambiguous output redirect.\n");
  jfree_remaining(ALLOC);
  exit(1);
}

int	get_redirection_input_fd(t_token *token)
{
  int	fd;
  char	*filename;

  fd = 0;
  if (token->stdin_type == FILE_REDIRECT)
    {
      filename = token->stdin_value;
      if ((fd = open(filename, O_RDONLY)) == -1)
	{
	  token->status_code = 1;
	  print_error(filename);
	  print_error(": ");
	  print_error(strerror(errno));
	  print_error(".\n");
	  return (0);
	}
    }
  return (fd);
}

int	get_redirection_output_fd(t_token *token)
{
  int	oflag;
  int	fd;
  char	*filename;

  fd = 1;
  if (token->stdout_type == NULL_REDIRECT)
    return (1);
  if (token->stdout_type == FILE_REDIRECT)
    oflag = O_WRONLY | O_CREAT | O_TRUNC;
  else
    oflag = O_WRONLY | O_CREAT | O_APPEND;
  filename = token->stdout_value;
  if ((fd = open(filename, oflag, S_IRUSR | S_IWUSR | S_IRGRP |
		                  S_IWGRP | S_IROTH)) == -1)
    {
      print_error(filename);
      print_error(": ");
      print_error(strerror(errno));
      print_error(".\n");
      return (-1);
    }
  return (fd);
}
