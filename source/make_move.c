/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:04:43 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/27 15:20:29 by yufonten         ###   ########.fr       */
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

/*int move(t_game *data, int key)
{
    if (key == A || key == UP)
    return (0);
}*/