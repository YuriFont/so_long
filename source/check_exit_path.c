/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:49:45 by yufonten          #+#    #+#             */
/*   Updated: 2024/03/06 21:34:25 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_exit(t_game *data, int y, int x)
{
	char	map;

	map = data->map.map[y][x];
	if (x < 0 || y < 0 || x > data->map.columns || y > data->map.rows)
		return ;
	if (map == 'P' || map == '1' || map == 'E' || map == 'C')
		return ;
	data->map.map[y][x] = 'P';
	find_exit(data, y + 1, x);
	find_exit(data, y - 1, x);
	find_exit(data, y, x + 1);
	find_exit(data, y, x - 1);
}

void	return_map(t_game *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (i == data->pos.y && j == data->pos.x)
			{
				j++;
				continue ;
			}
			if (data->map.map[i][j] == 'P')
				data->map.map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	check_exit_around(t_game *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'E')
			{
				data->pos_e.y = i;
				data->pos_e.x = j;
			}
			j++;
		}
		i++;
	}
	i = data->pos_e.y;
	j = data->pos_e.x;
	if (data->map.map[i + 1][j] == 'P' || data->map.map[i - 1][j] == 'P' ||
		data->map.map[i][j + 1] == 'P' || data->map.map[i][j - 1] == 'P')
		return ;
	throw_error(data, 'M', 0);
}

char	**create_aux_map(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while ()
	}

}

void	check_exit_path(t_game *data)
{
	int		y;
	int		x;
	char	**map;

	y = data->pos.y;
	x = data->pos.x;
	map = data->map.map;
	if (map[y + 1][x] == '0')
		y++;
	else if (map[y][x + 1] == '0')
		x++;
	else if (map[y - 1][x] == '0')
		y--;
	else if (map[y][x - 1] == '0')
		x--;
	else
		throw_error(data, 'M', 0);
	find_exit(data, y, x);
	check_exit_around(data);
	return_map(data);
}
