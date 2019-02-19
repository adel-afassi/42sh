/*
** 42shrc.c for  in /home/adel/delivery/42sh
** 
** Made by adel
** Login   <adel.afassi@epitech.eu>
** 
** Started on  Tue Apr 18 15:27:33 2017 adel
** Last update Sun Apr 30 21:43:52 2017 adel
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "42sh.h"
#include "config_rc.h"
#include "home.h"
#include "parser.h"
#include "helpers/memory.h"
#include "utils/get_next_line.h"

/*
** Load the 42shrc or create if it don't exist
** @param env_list (a linked list pointer containing multiples the env)
** @return code (int containing the last status function or 1 if error)
*/
int	load_42shrc(t_list *env_list)
{
  char	*path;
  char	*buffer;
  int	code;
  int	fd;

  code = 0;
  path = get_filepath_at_home(".42shrc", env_list);
  if (path == NULL)
    return (1);
  if ((fd = open(path, O_RDONLY | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR |
		 S_IRGRP | S_IWGRP | S_IROTH)) == -1)
    return (1);
  else
    {
      while ((buffer = get_next_line(fd)) != NULL)
	code = line_parser(buffer, &env_list);
    }
  return (code);
}
