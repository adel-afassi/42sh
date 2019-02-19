/*
** process.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Fri Apr  7 04:38:53 2017 Jérémy Sid Idris
** Last update Tue Apr 11 16:30:40 2017 adel
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "helpers/list.h"
#include "helpers/string.h"
#include "helpers/file.h"
#include "helpers/output.h"
#include "path.h"
#include "my_signal.h"
#include "binary.h"
#include "process.h"

int	spawn_pipe_process(int current_stdin, int pipe[2],
			   char **args, t_list *env)
{
  pid_t	child_pid;
  char	**envp;

  args[0] = find_realpath(args[0], env);
  envp = export_list(env);
  if (try_to_run_binary_validation(args[0]) == 1)
    return (ERROR_PID);
  if ((child_pid = fork()) == -1)
    fatal_exit("Cannot fork :/ \n");
  if (child_pid == 0)
    {
      if (pipe[0] >= 0)
	close(pipe[0]);
      dup_process_fd(current_stdin, pipe[1]);
      if (execve(args[0], args, envp) == -1)
	{
	  print_error(args[0]);
	  print_error(": Exec format error. Binary file not executable.\n");
	  return (ERROR_PID);
	}
    }
  return (child_pid);
}

int	spawn_end_pipe_process(int current_stdin, int current_stdout,
			       char **args, t_list *env)
{
  pid_t	end_pid;
  char	**envp;

  args[0] = find_realpath(args[0], env);
  envp = export_list(env);
  if (try_to_run_binary_validation(args[0]) == 1)
    return (ERROR_PID);
  if ((end_pid = fork()) == -1)
    fatal_exit("Cannot fork :/ \n");
  if (end_pid == 0)
    {
      dup_process_fd(current_stdin, current_stdout);
      if (execve(args[0], args, envp) == -1)
	{
	  print_error(args[0]);
	  print_error(": Exec format error. Binary file not executable.\n");
	  return (ERROR_PID);
	}
    }
  return (end_pid);
}

void	dup_process_fd(int current_stdin, int current_stdout)
{
  if (current_stdin != STDIN_FILENO)
    {
      dup2(current_stdin, STDIN_FILENO);
      close(current_stdin);
    }
  if (current_stdout != STDOUT_FILENO)
    {
      dup2(current_stdout, STDOUT_FILENO);
      close(current_stdout);
    }
}
