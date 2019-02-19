/*
** env.c for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 04:30:26 2017 Jérémy Sid Idris
** Last update Tue Jan 17 04:30:26 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/memory.h"
#include "helpers/string.h"
#include "helpers/array.h"
#include "42sh.h"
#include "env.h"

char	*get_env_value(char *name, t_list *env)
{
  int	begin_value;

  begin_value = -1;
  while (env != NULL)
    {
      if (is_corresponding_key(name, env->content, &begin_value))
	return (&env->content[begin_value]);
      env = env->next;
    }
  return (NULL);
}

void	update_env_value(char *name, char *value, t_list *env)
{
  int	begin_value;

  begin_value = -1;
  while (env != NULL)
    {
      if (is_corresponding_key(name, env->content, &begin_value))
	{
	  jfree(env->content);
	  env->content = value;
	  return ;
	}
      env = env->next;
    }
}

void		remove_env_value(char *name, t_list **env)
{
  t_list	*last;
  t_list	*tmp;
  int		begin_value;

  tmp = *env;
  last = NULL;
  begin_value = -1;
  while (tmp != NULL)
    {
      if (is_corresponding_key(name, tmp->content, &begin_value))
	{
	  if (last == NULL)
	    *env = tmp->next;
	  else
	    last->next = tmp->next;
	  jfree(tmp->content);
	  jfree(tmp);
	  return ;
	}
      last = tmp;
      tmp = tmp->next;
    }
}

int	is_corresponding_key(char *key, char *str, int *begin_value)
{
  int	i;

  i = 0;
  while (key[i] != 0)
    {
      if (str[i] == 0)
	return (0);
      if (key[i] != str[i])
	return (0);
      i = i + 1;
    }
  if (str[i] == '=')
    {
      *begin_value = i + 1;
      return (1);
    }
  return (0);
}

char	*format_env_entry(char **args)
{
  int	i;
  char	*formated;
  int	size;

  i = 0;
  size = (array_len(args) == 1 ? len(args[0]) : (len(args[0]) + len(args[1])));
  formated = jmalloc(sizeof(char) * size + 2, ALLOC);
  while (i < len(args[0]))
    {
      formated[i] = args[0][i];
      i = i + 1;
    }
  formated[i] = '=';
  i = i + 1;
  if (array_len(args) > 1)
    {
      while (*args[1] != '\0')
	{
	  formated[i] = *args[1];
	  i = i + 1;
	  args[1] = args[1] + 1;
	}
    }
  formated[i] = '\0';
  return (formated);
}
