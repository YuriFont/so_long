/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:11:12 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/27 14:33:43 by yufonten         ###   ########.fr       */
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
# define KID_B "./assets/ash_back.xpm"
# define KID_L "./assets/ash_left.xpm"
# define KID_R "./assets/ash_right.xpm"
# define KID_F "./assets/ash_front.xpm"
# define POK "./assets/pokeball.xpm"
# define EXIT "./assets/exit.xpm"

typedef struct s_map
{
	char	**map;
	int		rows;
	int		columns;
	int		colection;
	int		exit;
	int		person;
}	t_map;

typedef struct s_img
{
	void	*img_kidF;
	void	*img_kidB;
	void	*img_kidL;
	void	*img_kidR;
	void	*img_gram;
	void	*img_tree;
	void	*img_exit;
	void	*img_pok;
}	t_img;

typedef struct s_game
{
	void	*ptr_mlx;
	void	*w_mlx;
	t_map	map;
	t_img	img;
}	t_game;

/* init_map.c */
char	**create_map(char *file);
void	init_map(t_game *data, char *file);

/* check_error.c */
void	check_file(char *file);
void	check_file_ber(char *file);
int		check_rectangular(t_game *data);
int	check_assets(t_game *data);

/* exit_game.c */
void	free_map(t_game *data);

/* draw_map.c */
void	render_images(t_game *data);
void	put_image(t_game *data, char px, int x, int y);
void	draw_map(t_game *data);

#endif