/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:11:12 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/24 14:21:42 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/minilibx-linux/mlx.h"
# include "../libraries/get_next_line/get_next_line.h"
# include "../libraries/libft/libft.h"
# include <stdlib.h>

# define GRAM "./textures/gram.xpm"
# define TREE "./textures/tree.xpm"

typedef struct s_data
{
	void	*ptr_mlx;
	void	*w_mlx;
	void	*image_gram;
	void	*image_tree;
	int		lenght;
}	t_data;

/* init_map.c */
int	check_arq(char *arq);

#endif