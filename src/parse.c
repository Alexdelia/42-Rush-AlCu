/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:21:55 by adelille          #+#    #+#             */
/*   Updated: 2022/02/11 23:09:31 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alcu.h"

static void	n_heap(t_map *map, const char *file)
{
	size_t	i;

	i = 0;
	while (file[i])
	{
		if (file[i] == '\n')
			map->n_heap++;
		i++;
	}
}

static bool	check_digit(const char *file)
{
	size_t	i;
	bool	n;

	n = false;
	i = 0;
	while (file[i])
	{
		if (!(file[i] > '0' && file[i] < '9'))
		{
			if (file[i] == '\n')
			{
				if (n == true)
					return (!ft_pser("ERROR a line cannot be empty\n")); // tmp
				n = true;
			}
			else
				return (!ft_pser("ERROR input must only contain digit\n")); // tmp
			n = false;
		}
		i++;
	}
	return (true);
}

static size_t	line_to_size_t(const char *file, size_t *i)
{
	size_t	ret;

	ret = 0;
	while (file[*i] && file[*i] != '\n')
	{
		ret = ret * 10 + (file[*i] - '0');
		if (ret > UINT_MAX)
			return (!ft_pser("ERROR number of item on heap > UINT_MAX\n")); // tmp
		++*i;
	}
	if (ret == 0)
		return (!ft_pser("ERROR heap can't have 0 item\n")); // tmp
	if (file[*i])
		++*i;
	return (ret);
}

static bool	fill_map(t_map *map, const char *file)
{
	size_t	heap;
	size_t	i;

	heap = 0;
	i = 0;
	if (!check_digit(file))
		return (false);
	while (file[i])
	{
		map->map[heap] = line_to_size_t(file, &i);
		if (map->map[heap] == 0)
			return (false);
		map->n_item += map->map[heap];
		heap++;
	}
	return (true);
}

bool	parse(t_map *map, const int fd)
{
	char	*file;
	size_t	size;

	map->map = NULL;
	map->n_item = 0;
	map->n_heap = 0;
	map->winner = NO_WIN;
	file = gal(fd, &size);
	if (!file)
		return (!ft_pser("ERROR reading file\n")); // tmp
	else if (!size)
		return (!ft_pser("ERROR empty file\n")); // tmp
	n_heap(map, file); // should not need to check if n_heap > 0
	map->map = (size_t *)malloc(sizeof(size_t) * (map->n_heap + 1));
	if (!map->map)
		return (!ft_pser("ERROR malloc failed\n")); // tmp
	if (!fill_map(map, file))
	{
		free(file);
		return (clear_map(map));
	}
	free(file);
	return (true);
}
