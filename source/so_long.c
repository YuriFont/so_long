/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:10:31 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/22 16:36:15 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	initializing_window(t_data *data)
{
	data->ptr_mlx = mlx_init();
	if (!data->ptr_mlx)
		exit(1);
	data->w_mlx = mlx_new_window(data->ptr_mlx, 700, 500, "Test");
	if (!data->w_mlx)
	{
		free(data->ptr_mlx);
		exit(1);
	}
}

void	destroy_window(t_data *data)
{
	mlx_destroy_window(data->ptr_mlx, data->w_mlx);
	mlx_destroy_display(data->ptr_mlx);
	free(data->ptr_mlx);
	exit(0);
}

int	on_keypress(int key, t_data *data)
{
	if (key == 65307)
		destroy_window(data);
	printf("Pressed key: %d\n", key);
	return (0);
}

int	main(void)
{
	t_data	data;

	initializing_window(&data);	
	mlx_hook(data.w_mlx, 2, 1L<<0, on_keypress, &data);
	mlx_loop(data.ptr_mlx);
	return (0);
}