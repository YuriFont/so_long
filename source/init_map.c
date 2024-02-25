/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:04:41 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/25 14:41:54 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_rows(t_game *data, char *file)
{
	char	*line;
	int		rows;
	int		fd;

	rows = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		rows++;
	}
	data->map.rows = rows;
	close(fd);
}

void	map_columns(t_game *data, char *file)
{
	char	*line;
	int		columns;
	int		fd;

	columns = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line[columns] != '\n')
		columns++;
	close(fd);
	data->map.columns = columns;
}