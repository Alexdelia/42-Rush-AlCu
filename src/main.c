/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:53:36 by adelille          #+#    #+#             */
/*   Updated: 2022/02/12 17:52:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alcu.h"

bool	clear_map(t_map *map)
{
	if (map->map)
		free(map->map);
	return (false);
}

static bool	check_extension(char *file_name)
{
	int i;
	int j;
	char *ext;

	ext = ".map\0";
	i = 0;
	while (file_name[i] && file_name[i] != '.')
		i++;
	j = 0;
	while (file_name[i + j] && ext[j] && file_name[i + j] == ext[j])
		j++;
	if (j == 4 && file_name[i + j] == '\0' && ext[j] == '\0')
		return(true);
	return (!ft_pser("ERROR wrong map extension.\n")); // tmp
}

static bool	init_map(const int ac, char **av, t_map *map, int *fd)
{
	if (ac == 1)
		*fd = STDIN;
	else if (ac == 2)
	{
		if (!check_extension(av[1]))
			return (false);
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
	t_map	map;
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
		//ft_ps("\33[1;1H\33[2J");
		print_map(map);
		ia(&map);
	}
	print_winner(map.winner);
	clear_map(&map);
	return (0);
}
