/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:04:41 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/26 16:52:58 by yufonten         ###   ########.fr       */
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
		free(line);
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
	free(line);
	close(fd);
	data->map.columns = columns;
}

char	**create_map(char *file)
{
	int		fd;
	char	*line;
	char	*holder_map;
	char	*holder;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	holder_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		free(line);
		free(holder);
	}
	map = ft_split(holder_map, '\n');
	free(holder_map);
	close(fd);
	return (map);
}

void	init_map(t_game *data, char *file)
{
	map_columns(data, file);
	map_rows(data, file);
	data->map.map = create_map(file);
}
