/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:53:36 by adelille          #+#    #+#             */
/*   Updated: 2022/02/11 21:16:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alcu.h"

int	main(int ac, char **av)
{
	t_map	map; // int that represent winner is also saved in map

	if (ac != 2)
		return (ft_pser("no file\n") * 0 + 1); // tmp
	if (!parse(av[1], &map))
		return (2);
	print_map(map);
	ia(&map);
	while (map->n_heap > 0)
	{
		print_map(map);
		while (prompt(&map)) // need to get input from user, save it somewhere (will also show board)
			; // stay in the loop while the user didn't input something valid
		// prompt return a bool (true if input valid / false if not)
		// it also save input in map
		// this is tempoary, could be different logic
		if (map->n_heap == 0)
			break ;
		print_map(map);
		ia(&map);
	}
	print_winner(map->winner);
	// clear map if malloc
	return (0);
}
