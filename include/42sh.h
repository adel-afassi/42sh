/*
** 42sh.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include
**
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
**
** Started on  Sun Apr  9 14:52:02 2017 Jérémy Sid Idris
** Last update Tue Apr 18 15:33:02 2017 adel
*/

#ifndef M_42SH_H_
# define M_42SH_H_

# define EXIT_SUCCESS 0
# define EXIT_ERROR 1

# define SIGNAL_CONSTANT 128

# define MAX_LINE_SIZE 10240
# define TIMESTAMP_MAXSIZE 50

# define TYPE_UNKNOWN 1
# define TYPE_BINARY 2
# define TYPE_BUILTIN 3

# define UNKNOWN_PID 0
# define ERROR_PID -1

# define NULL_REDIRECT -1
# define FILE_REDIRECT 1
# define FILE_ADVANCED_REDIRECT 2
# define PIPE_REDIRECT 3

# define IN_ARROW 1
# define IN_DOUBLE_ARROW 10
# define OUT_ARROW 2
# define OUT_DOUBLE_ARROW 20

# define BTIN_KILL_BAD_ARG_NB "kill: Too few arguments.\n"
# define BTIN_KILL_BAD_ARG "kill: Arguments should be jobs or process id's.\n"
# define BTIN_KILL_UNKNOWN_SIGNAL ": Unknown signal; kill -l lists signals.\n"

# define PARSER_NULL_COMMAND_ERROR "Invalid null command.\n"
# define PARSER_LINE_TO_LONG "Exceeded max line size.\n"

# define TERM_SETUP_FAIL_ERROR "Error occured when setup term"

# define REDIRECT_MISSING_NAME 1
# define REDIRECT_AMBIGUOUS_INPUT 2
# define REDIRECT_AMBIGUOUS_OUTPUT 3

# define COMMAND_REGULAR 1
# define COMMAND_OR 2
# define COMMAND_AND 3

# define LINE_ALLOC 1
# define ALLOC 2

# define DEFAULT_PATH_VALUE "/usr/local/sbin:/usr/local/bin:" \
			    "/usr/sbin:/usr/bin:/sbin:/bin"

typedef struct		s_memory
{
  void			*pointer;
  int			type;
  struct s_memory	*next;
}			t_memory;

typedef struct	s_token
{
  char		**args;
  int		stdin_type;
  void		*stdin_value;
  int		stdout_type;
  void		*stdout_value;
  int		pid;
  int		type;
  int		status_code;
}		t_token;

typedef struct	s_command
{
  char		*data;
  int		type;
  int		status_code;
}		t_command;

typedef struct	s_signal
{
  int		id;
  char		*message;
  char		*name;
}		t_signal;

typedef struct	s_list
{
  char		*content;
  struct s_list	*next;
}		t_list;

typedef struct	s_builtin
{
  int		(*handle)(int, char **, t_list **);
  char		*command;
}		t_builtin;

void	show_prompt();
void	sigint_message();
void	catching_signals();
int	shell_loop(t_list *);

#endif /* !M_42SH_H_ */
