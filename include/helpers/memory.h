/*
1;2802;0c** memory.h for 42sh in /home/jeremy/Desktop/42sh/include/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Mon Apr 17 20:45:30 2017 Jérémy Sid Idris
** Last update Mon Apr 17 20:45:30 2017 Jérémy Sid Idris
*/

#ifndef MEMORY_H_
# define MEMORY_H_

void	*jmalloc(size_t, int);
void	jfree(void *);
void	jfree_remaining(int);

#endif /* !MEMORY_H_ */
