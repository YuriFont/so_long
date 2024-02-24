/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:10:31 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/24 16:07:43 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	initializing_window(t_game *data)
{
	data->ptr_mlx = mlx_init();
	if (!data->ptr_mlx)
		exit(1);
	data->w_mlx = mlx_new_window(data->ptr_mlx, 500, 400, "Test");
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
	if (ac == 2)
	{
		t_game	data;
		if (!check_arq(av[1]) || !(data.fd = open(av[1], O_RDONLY)))
		{
			ft_printf("Esse arquivo não existe ou não é .ber\n");
			exit(1);
		}
		initializing_window(&data);
		data.image_gram = mlx_xpm_file_to_image(data.ptr_mlx, GRAM, &data.lenght, &data.lenght);
		data.image_tree = mlx_xpm_file_to_image(data.ptr_mlx, TREE, &data.lenght, &data.lenght);
		data.image_kidf = mlx_xpm_file_to_image(data.ptr_mlx, KID_F, &data.lenght, &data.lenght);
		mlx_put_image_to_window(data.ptr_mlx, data.w_mlx, data.image_kidf, 50, 50);
		mlx_put_image_to_window(data.ptr_mlx, data.w_mlx, data.image_tree, 0, 0);
		mlx_put_image_to_window(data.ptr_mlx, data.w_mlx, data.image_tree, 0, 50);
		mlx_key_hook(data.w_mlx, on_keypress, &data);
		mlx_hook(data.w_mlx, 17, 0, destroy_window, &data);
		mlx_loop(data.ptr_mlx);
	}
	else
		ft_printf("Faltam argumentos");
		
	
	return (0);
}