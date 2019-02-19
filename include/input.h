/*
** input.h for input in /home/yoann/Documents/2017/42SH/keys_handling
**
** Made by Yoann Sarkissian
** Login   <yoann.sarkissian@epitech.eu>
**
** Started on  Sun Apr 16 23:44:16 2017 Yoann Sarkissian
** Last update Thu Apr 27 20:31:36 2017 Yoann
*/

#ifndef INPUT_H_
# define INPUT_H_

# include <termios.h>

typedef struct	s_input
{
  char		buffer[1024];
  int		len;
  int		pos;
  int	        len_key_history;
}		t_input;

char	*interactive_get_next_line(t_input *);
void	action(char *);
void	crs_left(t_input *);
void	crs_right(t_input *);
void	delete_print_char(t_input *);
void	rm_line(t_input *);
void	write_char(t_input *, char *, int);
char	*get_buffer(t_input *);
void	set_buffer(t_input *, char *);
void	append_buffer(t_input *, char *);
void	home_key(t_input *);
void	end_key(t_input *);
int	term_handling(struct termios *);
void	init_struct(t_input *);

#endif	/* INPUT_H_ */
