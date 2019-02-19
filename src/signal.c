/*
** signal.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Apr  4 02:18:33 2017 Jérémy Sid Idris
** Last update Wed Apr 12 19:53:06 2017 youcef chergui
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "42sh.h"
#include "helpers/string.h"
#include "helpers/number.h"
#include "helpers/array.h"
#include "helpers/output.h"
#include "my_signal.h"
#include "builtins/btin_kill.h"

static t_signal	g_signals[] =
{
  {1, "Hangup", "HUP"},
  {3, "Quit", "QUIT"},
  {4, "Illegal instruction", "ILL"},
  {5, "Trace/BPT trap", "TRAP"},
  {6, "Abort", "ABRT"},
  {7, "Bus error", "BUS"},
  {8, "Floating exception", "FPE"},
  {9, "Killed", "KILL"},
  {10, "User signal 1", "USR1"},
  {11, "Segmentation fault", "SEGV"},
  {12, "User signal 2", "USR2"},
  {14, "Alarm clock", "ALRM"},
  {15, "Terminated", "TERM"},
  {16, "Stack limit exceeded", "STKFLT"},
  {24, "Cputime limit exceeded", "XCPU"},
  {25, "Filesize limit exceeded", "XFSZ"},
  {26, "Virtual time alarm", "VTALRM"},
  {27, "Profiling time alarm", "PROF"},
  {29, "Pollable event occured", "POLL"},
  {30, "Power failure", "PWR"},
  {31, "Bad system call", "SYS"},
  {0, NULL, NULL}
};

int	show_siglist(int current_stdout)
{
  int	i;

  i = 0;
  while (g_signals[i].name != NULL)
    {
      my_putstr(current_stdout, g_signals[i].name);
      my_putstr(current_stdout, " ");
      i = i + 1;
    }
  my_putstr(current_stdout, "\n");
  return (0);
}

int	is_signal(char *name)
{
  int	i;

  i = 0;
  while (g_signals[i].id != 0)
    {
      if ((my_getnbr(name) == g_signals[i].id) ||
	  (my_strcmp(name, g_signals[i].name) == 0))
	return (g_signals[i].id);
      i = i + 1;
    }
  return (-1);
}

char	*get_message_for_signal(int signal)
{
  int	i;

  i = 0;
  while (g_signals[i].id != 0)
    {
      if (signal == g_signals[i].id)
	return (g_signals[i].message);
      i = i + 1;
    }
  return (NULL);
}
