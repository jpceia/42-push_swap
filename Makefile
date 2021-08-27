INCDIR		= .

LIBFTDIR	= ./libft
LIBFT		= libft/libft.a

SRCS		= main.c \
			  stack1.c stack2.c stack3.c stack4.c \
			  stack_pair1.c stack_pair2.c \
			  stack_pair3.c stack_pair4.c \
			  stack_pair_print.c \
			  push_swap1.c push_swap2.c push_swap_parse.c \
			  greedy_sort1.c greedy_sort2.c greedy_sort3.c \
			  radix_sort.c lis1.c lis2.c

SRCS_CHECKER= checker.c \
			  stack1.c stack2.c stack3.c stack4.c \
			  stack_pair1.c stack_pair2.c \
			  stack_pair3.c stack_pair4.c \
			  stack_pair_print.c \
			  push_swap1.c push_swap2.c push_swap_parse.c

OBJS		= $(SRCS:.c=.o)
OBJS_CHECKER= $(SRCS_CHECKER:.c=.o)

NAME		= push_swap

MAKE		= make
CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g

all:		$(NAME)

.c.o:
			${CC} ${CFLAGS} -I${INCDIR} -I$(LIBFTDIR) -c $< -o ${<:.c=.o}

$(LIBFT):
			$(MAKE) -C $(LIBFTDIR)

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) ${CFLAGS} $(OBJS) $(LIBFT) -o $(NAME)

checker:	$(OBJS_CHECKER) $(LIBFT)
			$(CC) ${CFLAGS} $(OBJS_CHECKER) $(LIBFT) -o checker

clean:
			$(MAKE) -C $(LIBFTDIR) clean
			$(RM) $(OBJS) $(OBJS_CHECKER)

fclean:
			$(MAKE) -C $(LIBFTDIR) fclean
			$(RM) $(OBJS) $(OBJS_CHECKER)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
