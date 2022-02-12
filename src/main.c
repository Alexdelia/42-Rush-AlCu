/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:53:36 by adelille          #+#    #+#             */
/*   Updated: 2022/02/12 16:49:33 by adelille         ###   ########.fr       */
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

/*static size_t	*map_cpy(size *src)
{
	size_t	*new;
	size_t	x;
	size_t	y;
	bool	one;

	x = 0;
	while (src[x] != 0)
		x++;
	new = (size_t *)malloc(sizeof(size_t) * x);
	if (!new)
		return (NULL);
	y = 0;
	x = 0;
	while (src[x] != 0)
	{
		one = false;
		while (src[x] == 1)
		{
			one = !one;
			x++;
		}
		if (one = true)
		{
			new[y] = 1;
			y++;
		}
		if (src[x] == 0)
		{
			new[y] = src[x];
			y++;
		}
	}
	new[y] = 0;
	return (new);
}*/

int check_extension(char *file_name)
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
		return(1);
	ft_pser("ERROR wrong map extension.\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map; // int that represent winner is also saved in map
	int		fd;

	if (!check_extension(av[1]))
		return (0);
	if (!init_map(ac, av, &map, &fd))
		return (1);
	if (!parse(&map, fd))
		return (2);
	/*map->simple = map_cpy(map->map);
	if (!map->simple)
		return (3);*/
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
