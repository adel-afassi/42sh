/*
** binary.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 04:15:27 2017 Jérémy Sid Idris
** Last update Wed Apr 12 18:40:32 2017 adel
*/

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include "helpers/list.h"
#include "helpers/string.h"
#include "helpers/file.h"
#include "helpers/output.h"
#include "path.h"
#include "my_signal.h"
#include "42sh.h"
#include "binary.h"

int	is_binary(char *arg, t_list *env)
{
  char	*real_path;

  real_path = find_realpath(arg, env);
  if (real_path == NULL)
    return (0);
  return (1);
}

int	try_to_run_binary_validation(char *file)
{
  int	error_nb;

  if ((error_nb = can_exec_file(file)) != 0)
    {
      print_error(file);
      if (error_nb == 1)
	print_error(": Command not found.\n");
      else
	print_error(": Permission denied.\n");
      return (1);
    }
  return (0);
}

int	handle_child_ended(int child_status)
{
  if (WIFEXITED(child_status))
    return (WEXITSTATUS(child_status));
  else if (WIFSIGNALED(child_status))
    {
      if (get_message_for_signal(WTERMSIG(child_status)) != NULL)
	{
	  print_error(get_message_for_signal(WTERMSIG(child_status)));
	  if (WCOREDUMP(child_status))
	    print_error(" (core dumped)");
	  print_error("\n");
	}
      return (WTERMSIG(child_status) + SIGNAL_CONSTANT);
    }
  return (0);
}
