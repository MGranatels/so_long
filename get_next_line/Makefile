NAME		= get_next_line.a

SRCS		=		get_next_line.c get_next_line_utils.c 

OBJS		= $(SRCS:.c=.o)

CC			= gcc

RM			= @rm -f

CFLAGS		= -Wall -Werror -Wextra -I.

.c.o:
				@$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
				@ar rc $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean: 	clean
				$(RM) $(NAME)

re: 		fclean all

bonus:		$(OBJS) $(BONUS_OBJS)
			ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: 	all clean fclean re bonus
