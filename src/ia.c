/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:44:05 by esafar            #+#    #+#             */
/*   Updated: 2022/02/12 14:34:13 by esafar           ###   ########.fr       */
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


void    ia(t_map *map)
{
	bool	take;
	size_t	i;
	
	if (map->map[0] % 4 == 1)
	    take = USER_TAKE;
	else
	    take = IA_TAKE
	i = 1;
	while (map->map[i] != 0)
	{
	    if (map->map[i] % 4 == 1)
		take = !take;
	    i++;
	}
	i--;
	if (take == USER_TAKE && map->map[i] % 4 != 1)
	    take(map->map[i] % 4 - 1);
	else if (take == IA_TAKE && map->map[i] % 4 > 0)
	    take(map->map[i] % 4 - 1);
	else
	    take(1);
}
