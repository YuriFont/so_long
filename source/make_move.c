/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:04:43 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/28 10:46:58 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_position(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'P')
			{
				data->pos.x = j;
				data->pos.y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	put_image_move(t_game *data, char px, int x, int y)
{
	if (px == 'P')
	{
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_kidF, x * 50, y * 50);
	}
	else if (px == 'B')
	{
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_kidB, x * 50, y * 50);
	}
	else if (px == 'L')
	{
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_kidL, x * 50, y * 50);
	}
	else if (px == 'R')
	{
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_kidR, x * 50, y * 50);
	}
	if (data->map.map[y][x] == 'C')
	{
		data->map.colection--;
		data->map.map[y][x] = '0';
	}
}

int	check_move(t_game *data, char px)
{
	if (px == '1' || (px == 'E' && data->map.colection != 0))
		return (0);
	return (1);
}

void	move(t_game *data, int key)
{
	if ((key == W || key == UP) &&
		check_move(data, data->map.map[data->pos.y - 1][data->pos.x]))
	{
		put_image(data, '0', data->pos.x, data->pos.y);
		put_image_move(data, 'B', data->pos.x, --data->pos.y);
	}
	else if ((key == S || key == DOWN) &&
		check_move(data, data->map.map[data->pos.y + 1][data->pos.x]))
	{
		put_image(data, '0', data->pos.x, data->pos.y);
		put_image_move(data, 'P', data->pos.x, ++data->pos.y);
	}
	else if ((key == A || key == LEFT) &&
		check_move(data, data->map.map[data->pos.y][data->pos.x - 1]))
	{
		put_image(data, '0', data->pos.x, data->pos.y);
		put_image_move(data, 'L', --data->pos.x, data->pos.y);
	}
	else if ((key == D || key == RIGHT) &&
		check_move(data, data->map.map[data->pos.y][data->pos.x + 1]))
	{
		put_image(data, '0', data->pos.x, data->pos.y);
		put_image_move(data, 'R', ++data->pos.x, data->pos.y);
	}
}
