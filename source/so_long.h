/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:11:12 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/22 17:00:43 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/minilibx-linux/mlx.h"
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

#endif