# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 10:48:42 by yufonten          #+#    #+#              #
#    Updated: 2024/02/24 14:32:42 by yufonten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SO_LONG = so_long.c\
			init_map.c
LIBMLX = libmlx_Linux.a
LIBFT = ./libraries/libft/
LIBFT_A = $(LIBFT)libft.a


all: $(NAME)

NAME:
		$(MAKE) -C $(LIBFT)
		cc -Wall -Wextra -Werror $(addprefix source/, $(SO_LONG)) $(addprefix source/, $(LIBMLX)) $(LIBFT_A) -Lmlx -lXext -lX11

clean:
		@$(MAKE) clean -C $(LIBFT)

fclean: clean
		@$(MAKE) fclean -C $(LIBFT)