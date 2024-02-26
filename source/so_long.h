/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:11:12 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/26 16:10:39 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/minilibx-linux/mlx.h"
# include "../libraries/libft/libft.h"
# include "../libraries/libft/get_next_line.h"
# include "../libraries/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>

# define GRAM "./assets/gram.xpm"
# define TREE "./assets/tree.xpm"
# define KID_F "./assets/ash_front.xpm"

typedef struct s_map
{
	int	rows;
	int	columns;
	char	**map;
}	t_map;

typedef struct s_game
{
	void	*ptr_mlx;
	void	*w_mlx;
	void	*image_gram;
	void	*image_tree;
	void	*image_kidf;
	t_map	map;
	int		lenght;
}	t_game;

/* init_map.c */
char	**create_map(char *file);

/* check_error.c */
int		check_file(char *file);

#endif