/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:00:13 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/27 20:45:29 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_map(t_game *data)
{
    int i;

    i = 0;
	while (data->map.map[i])
		free(data->map.map[i++]);
	free(data->map.map);
}

int	destroy_window(t_game *data)
{

	free_map(data);
	mlx_destroy_image(data->ptr_mlx, data->img.img_exit);
	mlx_destroy_image(data->ptr_mlx, data->img.img_gram);
	mlx_destroy_image(data->ptr_mlx, data->img.img_kidB);
	mlx_destroy_image(data->ptr_mlx, data->img.img_kidF);
	mlx_destroy_image(data->ptr_mlx, data->img.img_kidL);
	mlx_destroy_image(data->ptr_mlx, data->img.img_kidR);
	mlx_destroy_image(data->ptr_mlx, data->img.img_pok);
	mlx_destroy_image(data->ptr_mlx, data->img.img_tree);
	mlx_destroy_window(data->ptr_mlx, data->w_mlx);
	mlx_destroy_display(data->ptr_mlx);
	free(data->ptr_mlx);
	exit(0);
	return (0);
}
