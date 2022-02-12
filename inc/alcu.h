/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:47:54 by adelille          #+#    #+#             */
/*   Updated: 2022/02/12 18:52:30 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

# include "../libft/inc/libft.h"

# include <fcntl.h>

# define NO_WIN		0
# define IA_WIN		1
# define USER_WIN	2


# define NORMAL		true
# define REVERSE	false

typedef struct s_map
{
	size_t	*map; // tab of int size of number of row, each index holding the number of heaps
	size_t	n_item;
	size_t	n_heap;
	int		winner;
}			t_map;

bool	parse(t_map *map, const int fd);
void    ia(t_map *map);
bool	prompt(t_map *map);

void	print_map(t_map map);
void	print_winner(const int winner);
int		error(const char *str, const int ret);

bool	clear_map(t_map *map);

#endif
