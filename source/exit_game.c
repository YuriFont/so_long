/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:00:13 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/26 17:01:16 by yufonten         ###   ########.fr       */
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