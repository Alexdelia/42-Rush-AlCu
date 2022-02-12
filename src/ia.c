/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:44:05 by esafar            #+#    #+#             */
/*   Updated: 2022/02/12 14:58:54 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alcu.h"

#define IA_TAKE	    true
#define USER_TAKE   false // (last one)

/*int good_setup(t_map *map)
{
	if ((map->n_item - 1) % 4 == 0)
		return (1);
	return (0);
}

int next_winning_nb(t_map *map)
{
	int w_nb;

	w_nb = map->n_item;
	while ((w_nb - 1) % 4 != 0)
		w_nb--;
	return (w_nb);
}

void    ia(t_map *map)
{
	int start = 0;
	int w_nb = 0;
	int last_index = 0;

	if (start == 0)
	{
		w_nb = next_winning_nb(map);
		last_index = last_heap(map);
		if ((map->n_item - w_nb) < 4)
		{
			map->map[last_index] -= choice; // call func that returns value taken;
			map->n_item -= choice;
		}
	}*/
    
    // if (start != 0 && good_setup(map))


static bool take(t_map *map, const size_t i, const int n)
{
    if (n > map->map[i])
	return (!ft_pser("ERROR IA TAKE TOO MUCH\n"));
    map->map[i] -= n;
    map->n_item -= n;
    ft_ps("IA took ");
    ft_pn(n);
    write(1, "\n", 1);
    if (map->n_item == 0)
	map->winner = USER_WIN;
    return (true);
}

void    ia(t_map *map)
{
	bool	order;
	size_t	i;
	
	if (map->map[0] % 4 == 1)
	    order = USER_TAKE;
	else
	    order = IA_TAKE;
	i = 1;
	while (map->map[i] != 0)
	{
	    if (map->map[i] % 4 == 1)
		order = !order;
	    i++;
	}
	i--;
	if (order == USER_TAKE && map->map[i] % 4 != 1)
	    take(map, i, map->map[i] % 4);
	else if (order == IA_TAKE && map->map[i] % 4 > 0)
	    take(map, i, map->map[i] % 4);
	else
	{
	    take(map, i, 1);
	    ft_pserc("I am losing :,c\n", C_RED);
	}
}
