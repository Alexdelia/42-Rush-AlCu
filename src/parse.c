/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:21:55 by adelille          #+#    #+#             */
/*   Updated: 2022/02/13 12:50:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alcu.h"

static void	n_heap(t_map *map, const char *file, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (file[i] == '\n')
			map->n_heap++;
		i++;
	}
}

static bool	check_digit(const char *file, const size_t size)
{
	size_t	i;
	bool	n;

	n = false;
	i = 0;
	while (i < size)
	{
		if (file[i] < '0' && file[i] > '9')
		{
			if (file[i] == '\n')
			{
				if (n == true)
					return (error("a line cannot be empty", 0));
				n = true;
			}
			else
				return (error("input must only contain digit", 0));
			n = false;
		}
		i++;
	}
	return (true);
}

size_t	line_to_size_t(const char *file, size_t *i, const size_t size)
{
	size_t	ret;

	ret = 0;
	while (*i < size && file[*i] != '\n')
	{
		ret = ret * 10 + (file[*i] - '0');
		if (ret > 10000)
			return (error("number of item on heap > 10000", 0));
		++*i;
	}
	if (ret == 0)
		return (error("a heap cannot have 0 item", 0));
	if (*i < size)
		++*i;
	return (ret);
}

static bool	fill_map(t_map *map, const char *file, const size_t size)
{
	size_t	heap;
	size_t	i;

	heap = 0;
	i = 0;
	if (!check_digit(file, size))
		return (false);
	while (i < size)
	{
		map->map[heap] = line_to_size_t(file, &i, size);
		if (map->map[heap] == 0)
			return (false);
		map->n_item += map->map[heap];
		heap++;
	}
	map->map[heap] = 0;
	return (true);
}

bool	parse(t_map *map, const int fd)
{
	char	*file;
	size_t	size;

	file = gal(fd, &size, true);
	if (!file)
		return (error("reading file", 0));
	else if (!size)
	{
		free(file);
		return (error("empty file", 0));
	}
	n_heap(map, file, size);
	map->map = (size_t *)malloc(sizeof(size_t) * (map->n_heap + 1));
	if (!map->map)
	{
		free(file);
		return (error("malloc failed", 0));
	}
	if (!fill_map(map, file, size))
	{
		free(file);
		return (clear_map(map));
	}
	free(file);
	return (true);
}
