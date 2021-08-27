INCDIR		= .

LIBFTDIR	= ./libft
LIBFT		= libft/libft.a

OBJDIR		= obj

SRCS_PUSH_SWAP = \
			main.c \
			stack1.c stack2.c stack3.c stack4.c \
			stack_pair1.c stack_pair2.c \
			stack_pair3.c stack_pair4.c \
			stack_pair_print.c \
			push_swap1.c push_swap2.c push_swap_parse.c \
			greedy_sort1.c greedy_sort2.c greedy_sort3.c \
			radix_sort.c lis1.c lis2.c

SRCS_CHECKER = \
			checker.c \
			stack1.c stack2.c stack3.c stack4.c \
			stack_pair1.c stack_pair2.c \
			stack_pair3.c stack_pair4.c \
			stack_pair_print.c \
			push_swap1.c push_swap2.c push_swap_parse.c

OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:%.c=$(OBJDIR)/%.o)
OBJS_CHECKER = $(SRCS_CHECKER:%.c=$(OBJDIR)/%.o)

NAME		= push_swap

MAKE		= make
CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g

all:		$(NAME) checker

test:
	echo $(OBJS_PUSH_SWAP)

$(OBJDIR)/%.o:	%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@

$(LIBFT):
			$(MAKE) -C $(LIBFTDIR)

$(NAME):	$(LIBFT) $(OBJS_PUSH_SWAP)
			$(CC) $(CFLAGS) $? -o $@

checker:	$(LIBFT) $(OBJS_CHECKER)
			$(CC) $(CFLAGS) $? -o $@

clean:
			$(MAKE) -C $(LIBFTDIR) clean
			$(RM) -r $(OBJDIR)

fclean:		clean
			$(MAKE) -C $(LIBFTDIR) fclean
			$(RM) $(NAME) checker

re:			fclean all

.PHONY:		all clean fclean re
