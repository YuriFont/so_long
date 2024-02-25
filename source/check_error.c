/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:22:11 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/25 14:58:48 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(char *file)
{
	int		i;
	int		j;
	int		fd;

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
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Unable to find this map\n");
		exit(1);
	}
	close(fd);
	return (1);
}

int	check_rectangular(t_game *data)
{
	if (data->map.columns == data->map.rows)
		return (0);
	return (1);
}
