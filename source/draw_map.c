/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:18:57 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/27 15:33:52 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_images(t_game *data)
{
	data->img.img_gram = mlx_xpm_file_to_image(data->ptr_mlx,
			GRAM, &data->map.columns, &data->map.rows);
	data->img.img_tree = mlx_xpm_file_to_image(data->ptr_mlx,
			TREE, &data->map.columns, &data->map.rows);
	data->img.img_kidF = mlx_xpm_file_to_image(data->ptr_mlx,
			KID_F, &data->map.columns, &data->map.rows);
	data->img.img_kidB = mlx_xpm_file_to_image(data->ptr_mlx,
			KID_B, &data->map.columns, &data->map.rows);
	data->img.img_kidL = mlx_xpm_file_to_image(data->ptr_mlx,
			KID_L, &data->map.columns, &data->map.rows);
	data->img.img_kidR = mlx_xpm_file_to_image(data->ptr_mlx,
			KID_R, &data->map.columns, &data->map.rows);
	data->img.img_exit = mlx_xpm_file_to_image(data->ptr_mlx,
			EXIT, &data->map.columns, &data->map.rows);
	data->img.img_pok = mlx_xpm_file_to_image(data->ptr_mlx,
			POK, &data->map.columns, &data->map.rows);
}

void	put_image(t_game *data, char px, int x, int y)
{
	if (px == '1')
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_tree, x * 50, y * 50);
	else if (px == '0')
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_gram, x * 50, y * 50);
	else if (px == 'C')
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_pok, x * 50, y * 50);
	else if (px == 'E')
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_exit, x * 50, y * 50);
	else if (px == 'P')
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_kidF, x * 50, y * 50);
	else if (px == 'B')
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_kidB, x * 50, y * 50);
	else if (px == 'L')
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_kidL, x * 50, y * 50);
	else if (px == 'R')
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_kidR, x * 50, y * 50);
}

void	draw_map(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	render_images(data);
	while (data->map.map[i])
	{
		j = 0;
		while (j < data->map.columns)
		{
			put_image(data, data->map.map[i][j], j, i);
			j++;
		}
		i++;
	}
}
