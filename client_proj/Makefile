# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_norris_loves_the_norminette.c                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chuck <chuck@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2042/02/30 42:00:00 by chuck             #+#    #+#              #
#    Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re log

NAME		= client

CC			= gcc
CC_FLAGS	= -Wall -Wextra -Werror -g
CC_HEADERS	= -I incs

LIB_PATH	= ./libft
LIB_INCS	= -I $(LIB_PATH)/incs
LIB_LD		= $(LIB_PATH)/libft.a

RANDOM		= python -c 'import random;print random.randint(0, 256)' 

C_DIR		= srcs
H_DIR		= incs
O_DIR		= objs

C_FILES		= $(shell find $(C_DIR) -type f -follow -print | grep ".*\.c$$")
C_DIRS		= $(shell find $(C_DIR) -type d -follow -print)

H_FILES		= $(shell find $(H_DIR) -type f -follow -print | grep ".*\.h$$")

O_DIRS		= $(C_DIRS:$(C_DIR)%=$(O_DIR)%)
O_FILES		= $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)

all:
	@make -sC $(LIB_PATH)
	@make -s $(NAME)

$(NAME):		$(O_FILES) $(LIB_LD)
	@echo ""
	@$(CC) $^ -o $@ $(LIB_LD) -lncurses

$(O_DIR)/%.o:	$(C_DIR)/%.c $(H_FILES)
	@mkdir -p $(O_DIRS) $(O_DIR)
	@$(CC) $(CC_FLAGS) $(CC_HEADERS) $(LIB_INCS) -o $@ -c $< && \
	printf "\033[38;5;"$(shell $(RANDOM))"mC\033[0m"

clean:
	@rm -rf $(O_DIR)

fclean: clean
	@rm -rf $(NAME)

check:
	make -k -C tests/unit

log:
	touch /tmp/.debug_irc; clear; tail -f /tmp/.debug_irc

re: fclean all
