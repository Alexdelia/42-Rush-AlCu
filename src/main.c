/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:53:36 by adelille          #+#    #+#             */
/*   Updated: 2022/02/12 14:35:11 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alcu.h"

bool	clear_map(t_map *map)
{
	if (map->map)
		free(map->map);
	return (false);
}

static bool	init_map(const int ac, char **av, t_map *map, int *fd)
{
	if (ac == 1)
		*fd = STDIN;
	else if (ac == 2)
	{
		*fd = open(av[1], O_RDONLY);
		if (*fd == -1)
			return (!ft_pser("can't open file")); // tmp
	}
	else
		return (!ft_pser("ERROR\n")); // tmp
	map->map = NULL;
	map->n_item = 0;
	map->n_heap = 0;
	map->winner = NO_WIN;
	return (true);
}

int	main(int ac, char **av)
{
	t_map	map; // int that represent winner is also saved in map
	int		fd;

	if (!init_map(ac, av, &map, &fd))
		return (1);
	if (!parse(&map, fd))
		return (2);
	print_map(map);
	ia(&map);
	while (map.n_item > 0)
	{
		print_map(map);
		if (prompt(&map))
			break ;
		print_map(map);
		ia(&map);
	}
	print_winner(map.winner);
	clear_map(&map);
	return (0);
}
