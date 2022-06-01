# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 17:02:19 by mgranate          #+#    #+#              #
#    Updated: 2022/06/01 01:27:13 by anne-sophie      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~ SOURCES ~~~~~~ */
NAME		=	so_long
CC			=	clang

SRCS		=	srcs/main.c		   \
				srcs/error_check.c \
				srcs/read_map.c	   \
				srcs/input_img.c   \
				srcs/move_char.c

LIBFT		=	libft/libft.a
PRINTF		=	printf/libftprintf.a
GNL			=	get_next_line/get_next_line.a

CFLAGS		=	-Wall -Wextra -Werror -g
MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz

RM			=	rm -f

OBJS		=	$(SRCS:%.c=%.o)

ifeq ($(shell uname), Linux)
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
endif

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo $(CYAN) " - Compiling $@" $(RED)
			@make -C libft
			@make -C printf
			@make -C get_next_line
			@make clean -C libft
			@make clean -C printf
			@make clean -C get_next_line
			$(CC) $(SRCS) $(LIBFT) $(PRINTF) $(GNL) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

clean:
			@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
			$(RM) $(OBJS)

fclean:		clean
			@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
			$(RM) $(NAME)
			$(RM) *.out
			make fclean -C libft/
			make fclean -C printf/
			make fclean -C get_next_line/

re:			fclean all

git:
	@git add .
	@git commit -m "$m"
	@git push
	@echo "Commit sent to github"
# To call: make git m="my commit"

.PHONY:		all clean fclean re