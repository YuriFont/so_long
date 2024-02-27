/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:04:43 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/27 15:49:57 by yufonten         ###   ########.fr       */
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

void	move(t_game *data, int key)
{
	if ((key == W || key == UP) &&
		data->map.map[data->pos.y - 1][data->pos.x] != '1')
	{
		put_image(data, '0', data->pos.x, data->pos.y);
		put_image(data, 'B', data->pos.x, --data->pos.y);
	}
	else if ((key == S || key == DOWN) &&
		data->map.map[data->pos.y + 1][data->pos.x] != '1')
	{
		put_image(data, '0', data->pos.x, data->pos.y);
		put_image(data, 'P', data->pos.x, ++data->pos.y);
	}
	else if ((key == A || key == LEFT) &&
		data->map.map[data->pos.y][data->pos.x - 1] != '1')
	{
		put_image(data, '0', data->pos.x, data->pos.y);
		put_image(data, 'L', --data->pos.x, data->pos.y);
	}
	else if ((key == D || key == RIGHT) &&
		data->map.map[data->pos.y][data->pos.x + 1] != '1')
	{
		put_image(data, '0', data->pos.x, data->pos.y);
		put_image(data, 'R', ++data->pos.x, data->pos.y);
	}
}

void	put_image(t_game *data, char px, int x, int y);