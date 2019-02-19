/*
** parser.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 02:45:46 2017 Jérémy Sid Idris
** Last update Mon Apr 17 11:03:44 2017 adel
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "helpers/output.h"
#include "helpers/array.h"
#include "helpers/string.h"
#include "helpers/memory.h"
#include "pipeline.h"
#include "builtin.h"
#include "binary.h"
#include "token.h"
#include "history.h"
#include "command.h"
#include "42sh.h"
#include "parser.h"

/*
** Parse a line (as char *) and transform it to commands (as t_command *)
** Call command parser to parse every commands and return last command code
** @param line (a line containing multiples commands)
** @param env (an array of t_list pointers)
** @return status (the final status code of line)
*/
int		line_parser(char *line, t_list **env)
{
  t_command	**cmds;
  int		i;
  char		exit_req;

  if (len(line) > MAX_LINE_SIZE)
    return (print_error(PARSER_LINE_TO_LONG));
  exit_req = false;
  save_history(epur_str(line), *env);
  if ((cmds = make_commands(line)) == NULL)
    return (print_error(PARSER_NULL_COMMAND_ERROR));
  i = 0;
  while (cmds[i] != NULL)
    {
      if (my_strcmp(cmds[i]->data, "") != 0 &&
	  (cmds[i]->type == COMMAND_REGULAR ||
	  (cmds[i]->type == COMMAND_OR && cmds[i - 1]->status_code != 0) ||
	   (cmds[i]->type == COMMAND_AND && cmds[i - 1]->status_code == 0)))
      	cmds[i]->status_code = command_parser(cmds[i]->data, env, &exit_req);
      else
	cmds[i]->status_code = (i > 0 ? cmds[i - 1]->status_code : 0);
      i = i + 1;
    }
  return (get_line_code(exit_req, (i > 0 ? cmds[i - 1]->status_code : 0)));
}

int		command_parser(char *command, t_list **env,
				  char *force_exit)
{
  t_token	*token_list;
  char		**args_token;
  char		**buffer_tokens;
  int		i;

  buffer_tokens = my_str_to_wordtab(command, '|');
  i = array_len(buffer_tokens) - 1;
  token_list = NULL;
  while (i >= 0)
    {
      buffer_tokens[i] = epur_str(buffer_tokens[i]);
      args_token = my_str_to_wordtab(buffer_tokens[i], ' ');
      token_list = add_token(token_list, args_token);
      if (is_null_token(token_list))
	{
	  print_error(PARSER_NULL_COMMAND_ERROR);
	  jfree_remaining(ALLOC);
	  exit(EXIT_ERROR);
	}
      if (i == (array_len(buffer_tokens) - 1) &&
	  my_strcmp(args_token[0], "exit") == 0)
	*force_exit = true;
      i = i - 1;
    }
  return (pipeline_tokens(token_list, env));
}

int	get_line_code(char exit_req, int last_status_code)
{
  if (exit_req == true)
    {
      jfree_remaining(ALLOC);
      exit(last_status_code);
    }
  return (last_status_code);
}
