# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 17:02:19 by mgranate          #+#    #+#              #
#    Updated: 2022/05/26 20:06:53 by mgranate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~ SOURCES ~~~~~~ */
NAME		=	so_long
CC			=	clang

SRCS		=	srcs/main.c \
				srcs/error_check.c \
				srcs/read_map.c \

LIBFT		=	libft/libft.a
PRINTF		=	printf/libftprintf.a
CFLAGS		=	-Wall -Wextra -Werror
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
			@make clean -C libft
			@make clean -C printf
			$(CC) $(SRCS) $(LIBFT) $(PRINTF) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

clean:
			@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
			$(RM) $(OBJS)

fclean:		clean
			@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
			$(RM) $(NAME)
			$(RM) *.out
			make fclean -C libft/

re:			fclean all

git:
	@git add .
	@git commit -m "$m"
	@git push
	@echo "Commit sent to github"
# To call: make git m="my commit"

.PHONY:		all clean fclean re