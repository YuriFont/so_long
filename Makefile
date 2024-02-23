# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 10:48:42 by yufonten          #+#    #+#              #
#    Updated: 2024/02/01 10:48:47 by yufonten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SO_LONG = so_long.c
LIBMLX = libmlx_Linux.a

NAME:
		cc -Wall -Wextra -Werror $(addprefix source/, $(SO_LONG)) $(addprefix source/, $(LIBMLX)) -Lmlx -lXext -lX11

all: $(NAME)