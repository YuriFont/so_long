# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 10:48:42 by yufonten          #+#    #+#              #
#    Updated: 2024/02/26 17:02:24 by yufonten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SOURCE = ./source/
SO_LONG_C = $(SOURCE)so_long.c\
			$(SOURCE)create_map.c\
			$(SOURCE)check_error.c\
			$(SOURCE)exit_game.c

LIBMLX = ./libraries/minilibx-linux/
LIBMLX_A = $(LIBMLX)libmlx_Linux.a
LIBFT = ./libraries/libft/
LIBFT_A = $(LIBFT)libft.a
FT_PRINTF = ./libraries/ft_printf/
FT_PRINTF_A = $(FT_PRINTF)libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx -lXext -lX11
RM = rm -rf

NAME:
		$(MAKE) -C $(LIBFT)
		$(MAKE) -C $(FT_PRINTF)
		$(MAKE) -C $(LIBMLX)
		$(CC) $(CFLAGS) $(SO_LONG_C) $(LIBMLX_A) $(LIBFT_A) $(FT_PRINTF_A) $(MLXFLAGS) -o $(NAME)

clean:
		@$(MAKE) clean -C $(LIBFT)
		@$(MAKE) clean -C $(FT_PRINTF)
		@$(MAKE) clean -C $(LIBMLX)

fclean: clean
		@$(MAKE) fclean -C $(LIBFT)
		@$(MAKE) fclean -C $(FT_PRINTF)
		$(RM) $(NAME)

all: $(NAME)