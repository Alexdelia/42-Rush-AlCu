/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:53:36 by adelille          #+#    #+#             */
/*   Updated: 2022/02/12 11:05:29 by adelille         ###   ########.fr       */
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

void	print_map(t_map map)
{
	int j = 0;
	int len = 0;
	int diff = 0;
	int highest_len = 0;

	while (map.map[j])
	{
		len = map.map[j];
		if (len > highest_len)
			highest_len = len;
		j++;
	}
	j = 0;
	while (map.map[j])
	{
		len = map.map[j];
		diff = highest_len - len;
		while (diff > 0)
		{
			write(1, " ", 1);
			diff--;
		}
		while (len > 0)
		{
			write(1, "| ", 2);
			len--;
		}
		write(1, "\n", 1);
		j++;
	}
	return ;
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
	//ia(&map);
	while (map.n_item > 0)
	{
		print_map(map);
		if (prompt(&map)) // need to get input from user, save it somewhere
			break ;
		// stay in the prompt while the user didn't input something valid
		// prompt return a bool (true if user lose / false if game continue)
		// it also save input in map
		// this is tempoary, could be different logic
		print_map(map);
		//ia(&map);
	}
	//print_winner(map.winner); // if winner == NO_WIN, don't print anything
	clear_map(&map);
	return (0);
}
