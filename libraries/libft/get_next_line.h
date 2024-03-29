/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:41:31 by yufonten          #+#    #+#             */
/*   Updated: 2024/02/26 15:19:50 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*buf;
	struct s_list	*next;
}	t_list;

int		found_newline(t_list *list);
t_list	*find_last_node(t_list *list);
int		len_to_newline(t_list *list);
void	copy_str_list(t_list *list, char *str);
void	clear_list(t_list **list, t_list *clean_node, char *buf);
char	*get_next_line(int fd);

#endif
