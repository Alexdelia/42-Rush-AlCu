/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:53:36 by adelille          #+#    #+#             */
/*   Updated: 2022/02/11 23:04:00 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alcu.h"

bool	clear_map(t_map *map)
{
	if (map->map)
		free(map->map);
	return (false);
}

int	main(int ac, char **av)
{
	t_map	map; // int that represent winner is also saved in map
	int		fd;

	// init fd can be in parse or somewhere else than main
	if (ac == 1)
		fd = STDIN;
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (ft_pser("can't open file"));
	}
	else
		return (ft_pser("ERROR\n") * 0 + 2); // tmp
	if (!parse(&map, fd))
		return (3);
	print_map(map);
	ia(&map);
	while (map.n_item > 0)
	{
		print_map(map);
		while (prompt(&map)) // need to get input from user, save it somewhere (will also show board)
			; // stay in the loop while the user didn't input something valid
		// prompt return a bool (true if input valid / false if not)
		// it also save input in map
		// this is tempoary, could be different logic
		if (map.n_item == 0)
			break ;
		print_map(map);
		ia(&map);
	}
	print_winner(map.winner);
	clear_map(&map);
	return (0);
}
