/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:44:05 by esafar            #+#    #+#             */
/*   Updated: 2022/02/12 19:08:23 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alcu.h"

static bool	find_reverse(t_map *map, size_t i)
{
	size_t	n;

	if (map->map[i - 1] != 1)
		return (false);
	n = 0;
	i--;
	while (i >= 0 && map->map[i] == 1)
	{
		n++;
		i--;
	}
	return (n % 2);
}

static bool	case_4(t_map *map, bool *order)
{
	size_t	i;

	i = 0;
	while (map->map[i] != 0)
	{
		if (map->map[i] > 4)
			return (false);
		i++;
	}
	i--;
	if (find_reverse(map, i))
		*order = REVERSE;
	else
		*order = NORMAL;
	return (true);
}

static void	case_regular(t_map *map, size_t *i, bool *order)
{
	if (map->map[0] % 4 == 1)
		*order = REVERSE;
	else
		*order = NORMAL;
	if (map->map[1] > 0)
	{
		*i = 1;
		while (map->map[*i + 1] != 0)
		{
			if (map->map[*i] % 4 == 1)
				*order = !*order;
			++*i;
		}
	}
	else
		*i = 0;
}

static bool	take(t_map *map, const size_t i, const size_t n)
{
	//fprintf(stderr, "[i] n > item = [%ld] %ld > %ld\n", n, i, map->map[i]);
	if (n > map->map[i])
		return (error("IA TAKE TOO MUCH", 0));
	map->map[i] -= n;
	map->n_item -= n;
	ft_ps("IA took ");
	ft_pn(n);
	write(1, "\n", 1);
	if (map->n_item == 0)
		map->winner = USER_WIN;
	return (true);
}

void	ia(t_map *map)
{
	bool	order;
	size_t	i;

	if (!case_4(map, &order))
		case_regular(map, &i, &order);
	if (order == NORMAL && map->map[i] % 4 != 1)
	{
		ft_pserc("NORMAL\n", C_GREEN);
		take(map, i, ((map->map[i] - 1) % 4));
	}
	else if (order == REVERSE && map->map[i] % 4 > 0)
	{
		ft_pserc("REVERSE\n", C_YELLOW);
		take(map, i, ((map->map[i]) % 4));
	}
	else
	{
		ft_pserc("I am losing :,c\n", C_RED);
		take(map, i, 1);
	}
}
