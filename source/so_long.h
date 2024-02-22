/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:11:12 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/22 16:26:47 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/minilibx-linux/mlx.h"
# include <stdlib.h>

typedef struct s_data
{
	void	*ptr_mlx;
	void	*w_mlx;
}	t_data;

#endif