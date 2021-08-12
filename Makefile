INCDIR		= .

LIBFTDIR	= ./libft
LIBFT		= libft/libft.a

SRCS		= main.c \
			  stack1.c stack2.c stack3.c \
			  double_stack_print.c \
			  double_stack1.c double_stack2.c \
			  double_stack3.c double_stack4.c \
			  push_swap1.c push_swap2.c push_swap_parse.c \
			  greedy_sort.c radix_sort.c lis.c
OBJS		= $(SRCS:.c=.o)

NAME		= push_swap

MAKE		= make
CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g

all:		$(NAME)

.c.o:
			${CC} ${CFLAGS} -I${INCDIR} -I$(LIBFTDIR) -c $< -o ${<:.c=.o}

$(LIBFT):
			$(MAKE) bonus -C $(LIBFTDIR)

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(OBJS) $(LIBFT) -o $(NAME)

clean:
			$(MAKE) -C $(LIBFTDIR) clean
			$(RM) $(OBJS)

fclean:
			$(MAKE) -C $(LIBFTDIR) fclean
			$(RM) $(OBJS)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
