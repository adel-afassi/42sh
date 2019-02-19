##
## Makefile for 42sh in /home/jeremy/Desktop/42sh
## 
## Made by Jérémy Sid Idris
## Login   <jeremy.sid-idris@epitech.eu>
## 
## Started on  Thu Apr 13 17:18:23 2017 Jérémy Sid Idris
## Last update Mon May  1 16:06:32 2017 adel
##

COLOR_OFF =     \x1b[0m
COLOR =         \x1b[32;01m
PROG_OK =       $(COLOR)[Program Compiled]$(COLOR_OFF)

CC	=	gcc

SRC	=	src/helpers/output.c		\
		src/helpers/string.c		\
		src/helpers/string_2.c		\
		src/helpers/string_3.c		\
		src/helpers/number.c		\
		src/helpers/array.c		\
		src/helpers/memory.c		\
		src/helpers/list.c		\
		src/helpers/file.c		\
		src/utils/get_next_line.c	\
		src/builtins/btin_termname.c	\
		src/builtins/btin_which.c	\
		src/builtins/btin_repeat.c	\
		src/builtins/btin_where.c	\
		src/builtins/btin_cd.c		\
		src/builtins/btin_exit.c	\
		src/builtins/btin_setenv.c	\
		src/builtins/btin_unsetenv.c	\
		src/builtins/btin_env.c		\
		src/builtins/btin_echo.c	\
		src/builtins/btin_history.c	\
		src/builtins/btin_kill.c	\
		src/prompt/terminal.c		\
		src/prompt/write_char.c		\
		src/prompt/keys.c		\
		src/prompt/handler.c		\
		src/prompt/prompt.c		\
		src/config_rc.c			\
		src/command.c			\
		src/redirection.c		\
		src/pipeline.c			\
		src/process.c			\
		src/signal.c			\
		src/parser.c			\
		src/date.c			\
		src/history.c			\
		src/home.c			\
		src/builtin.c			\
		src/binary.c			\
		src/env.c			\
		src/path.c			\
		src/token.c			\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

CFLAGS	=	-Wextra -Wall -Werror -Iinclude/ -g3

LDFLAGS =	-lncurses

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo -e "$(PROG_OK)"

norm:
	cp -r ./ /tmp/rendu
	@echo "==========NORM TRACES=========="
	python tests/norm.py /tmp/rendu -nocheat -malloc
	@echo "==========END NORM TRACES=========="
test:
	cp $(NAME) ./tests/mysh
	cd tests ; sh tester.sh

.PHONY: all clean fclean re norm test
