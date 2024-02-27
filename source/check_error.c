/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:22:11 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/27 14:36:15 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_ber(char *file)
{
	int	i;
	int	j;

	i = ft_strlen(file);
	j = 1;
	while (j < 5)
	{
		if (file[i - j] != 'r' && file[i - j] != 'e'
			&& file[i - j] != 'b' && file[i - j] != '.')
		{
			ft_printf("Error: This file is not .ber\n");
			exit(1);
		}
		j++;
	}
}

void	check_file(char *file)
{
	int		fd;

	check_file_ber(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Unable to find this map\n");
		exit(1);
	}
	close(fd);
}

int	check_rectangular(t_game *data)
{
	if (data->map.rows == data->map.columns)
		return (1);
	if (data->map.rows <= 2 || data->map.columns <= 2)
		return (1);
	return (0);
}

int	check_assets(t_game *data)
{
	if (data->map.colection < 1)
		return (1);
	if (data->map.person != 1)
		return (1);
	if (data->map.exit != 1)
		return (1);
	return (0);
}
