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

# NAME		= client
CLIENT      = client_proj
SERVEUR     = serveur_proj

all:
	@make -j8 -C $(CLIENT)
	@make -j8 -C $(SERVEUR)
	@cp $(CLIENT)/client .
	@cp $(SERVEUR)/serveur .

clean:
	@make -C $(CLIENT) clean 
	@make -C $(SERVEUR) clean 

fclean: clean
	@make -C $(CLIENT) fclean 
	@make -C $(SERVEUR) fclean 

re: fclean all

# make check:
# 	make -k -C tests/unit

log:
	touch /tmp/.debug_irc; clear; tail -f /tmp/.debug_irc

re: fclean all
