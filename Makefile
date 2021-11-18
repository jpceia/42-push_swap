# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 23:00:40 by jpceia            #+#    #+#              #
#    Updated: 2021/11/17 23:58:50 by jpceia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

FT_DIR      = ./libft

INC_DIR     = headers

SRC_DIR		= src
OBJ_DIR		= obj

SRCS_PUSH_SWAP = \
			$(shell find $(addprefix $(SRC_DIR)/, \
				stack stack_pair utils lis sorters) -name '*.c' -type f) \
			$(SRC_DIR)/parser.c \
			$(SRC_DIR)/main.c

SRCS_CHECKER = \
			$(shell find $(addprefix $(SRC_DIR)/, \
				stack stack_pair utils) -name '*.c' -type f) \
			$(SRC_DIR)/parser.c \
			$(SRC_DIR)/checker.c

OBJS_PUSH_SWAP	= $(SRCS_PUSH_SWAP:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_CHECKER	= $(SRCS_CHECKER:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			= gcc
RM			= rm -f
OS          = $(shell uname)

FLAGS_WARN  = -Wall -Wextra -Werror
FLAGS_INC   = -I$(INC_DIR) -I$(FT_DIR)
FLAGS_DEBUG = -g -DDEBUG
FLAGS_OPT   = -O3
FLAGS_FT    = -L$(FT_DIR) -lft

CFLAGS      = $(FLAGS_WARN) $(FLAGS_OPT) $(FLAGS_INC) 
LDFLAGS     = $(FLAGS_WARN) $(FLAGS_OPT) $(FLAGS_FT)

all:		$(NAME) checker

test:
			echo $(SRCS_SHARED)

# Libft
libft:
			$(MAKE) -C $(FT_DIR)

# Compilation
$(OBJ_DIR)/%.o:  $(SRC_DIR)/%.c
			@mkdir -p $(dir $@)
			$(CC) -c $< -o $@ $(CFLAGS)

# Linking - push_swap
$(NAME):	$(OBJS_PUSH_SWAP)
			$(MAKE) -C $(FT_DIR)
			$(CC) $^ -o $@ $(LDFLAGS)

# Linking - Checker
checker:	$(OBJS_CHECKER)
			$(MAKE) -C $(FT_DIR)
			$(CC) $^ -o $@ $(LDFLAGS)

# Cleaning
clean:
			$(MAKE) -C $(FT_DIR) clean
			$(RM) -rf $(OBJ_DIR)

fclean:     clean
			$(MAKE) -C $(FT_DIR) fclean
			$(RM) $(NAME) checker

# Debugging build
debug:      CFLAGS += $(FLAGS_DEBUG)
debug:      LDFLAGS += $(FLAGS_DEBUG)
debug:      re

# Rebuid
re:         fclean all

.PHONY:     all clean fclean re debug
