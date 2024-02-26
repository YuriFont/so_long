/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:10:31 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/26 20:05:06 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	initializing_window(t_game *data)
{
	data->ptr_mlx = mlx_init();
	if (!data->ptr_mlx)
		exit(1);
	data->w_mlx = mlx_new_window(data->ptr_mlx, (data->map.columns) * 50, data->map.rows * 50, "Pokemon");
	if (!data->w_mlx)
	{
		free(data->ptr_mlx);
		exit(1);
	}
}

int	destroy_window(t_game *data)
{
	mlx_destroy_window(data->ptr_mlx, data->w_mlx);
	mlx_destroy_display(data->ptr_mlx);
	free(data->ptr_mlx);
	exit(0);
	return (0);
}

int	on_keypress(int key, t_game *data)
{
	if (key == 65307)
		destroy_window(data);
	printf("Pressed key: %d\n", key);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	data;

	if (ac != 2)
	{
		ft_printf("Wrong initialization\nEx: ./so_long file.ber");
		exit(1);	
	}
	check_file(av[1]);
	init_map(&data, av[1]);
	initializing_window(&data);
	mlx_key_hook(data.w_mlx, on_keypress, &data);
	mlx_hook(data.w_mlx, 17, 0, destroy_window, &data);
	draw_map(&data);
	mlx_loop(data.ptr_mlx);
	free_map(&data);
	return (0);
}