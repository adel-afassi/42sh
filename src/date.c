/*
** date.c for  in /home/youcef/delivery/PSU/42sh
** 
** Made by youcef chergui
** Login   <youcef.chergui@epitech.net>
** 
** Started on  Tue Apr 11 04:06:30 2017 youcef chergui
** Last update Tue Apr 11 05:00:38 2017 youcef chergui
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "helpers/memory.h"
#include "42sh.h"
#include "date.h"

char	*convert_timestamp_to_date(long timestamp)
{
  struct tm	*tm;
  char		*date;

  if ((tm = localtime(&timestamp)) == NULL)
    return (NULL);
  date = jmalloc(TIMESTAMP_MAXSIZE, LINE_ALLOC);
  if ((strftime(date, TIMESTAMP_MAXSIZE, "%a. %d %b.\t%H:%M:%S", tm)) == 0)
    return (NULL);
  return (date);
}
