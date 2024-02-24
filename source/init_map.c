/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:04:41 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/24 15:52:14 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arq(char *arq)
{
	int		i;
	int		j;
	char	c;

	i = ft_strlen(arq);
	j = 1;
	while (j < 5)
	{
		c = arq[i - j];
		if (c != 'r' && c != 'e'&& c != 'b' && c != '.')
			return (0);
		j++;
	}
	return (1);
}