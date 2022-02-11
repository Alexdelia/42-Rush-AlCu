/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:21:55 by adelille          #+#    #+#             */
/*   Updated: 2022/02/11 21:43:26 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alcu.h"

bool	parse(t_map *map, const int fd)
{
	char	*file;
	size_t	size;

	map->map = NULL;
	map->n_heap = 0;
	map->n_row = 0;
	map->winner = NO_WIN;
	file = gal(fd, &size);
	if (!file)
		return (!ft_pser("ERROR reading file\n")); // tmp
	else if (!size)
		return (!ft_pser("ERROR empty file\n")); // tmp
	// now:
	// - go through char *file
	// - count number of row (save in map->n_row)
	// - map->map = (int *)malloc(sizeof(int) * (row + 1));
	// 
	// - check if every row only has digits (empty row is error)
	// - check if row number is > 0 and < MAX (we can store an unsigned long, but I would prefer checking for INT_MAX)
	// - if one check return false, need to print reason, free(file), clear_map(&map) and return false
	//
	// - adding each number of each row to map->map[row] and map->n_heap += map->map[row]

	free(file);
	return (true);
}
