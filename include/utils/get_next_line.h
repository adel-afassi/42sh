/*
** get_next_line.h for getnextline in /home/jeremy/Delivery/CPE_2016_getnextline
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Mon Jan  9 02:12:47 2017 Jérémy Sid Idris
** Last update Tue Apr 11 00:48:41 2017 youcef chergui
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (1)
# endif

char	*get_next_line(const int);
char	*read_data(int, char *, int);
char	*append_begin_buffer(int *, int *, int *, int);
char	*my_alloc(char *, int, int *);
void	cut_buffer(int);

#endif /* !GET_NEXT_LINE_H_ */
