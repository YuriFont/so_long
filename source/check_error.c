/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:22:11 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/26 16:47:58 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_ber(char *file)
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
	return (0);
}

int	check_file(char *file)
{
	int		fd;
	char	*line;

	check_file_ber(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Unable to find this map\n");
		exit(1);
	}
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error: The .ber file is empty\n");
		free(line);
		exit(1);
	}
	free(line);
	close(fd);
	return (1);
}

int	check_rectangular(t_game *data)
{
	return (data->map.rows == data->map.columns ? 0 : 1);
}
