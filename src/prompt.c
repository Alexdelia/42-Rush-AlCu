/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:15:05 by adelille          #+#    #+#             */
/*   Updated: 2022/02/12 11:00:13 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alcu.h"

static size_t	n_item_last_heap(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map[i] != 0)
		i++;
	return (map->map[i]);
}

bool	prompt(t_map *map)
{
	char	*input;
	size_t	size;
	size_t	choice;
	size_t	last_index;

	last_index = last_heap(map);
	choice = 0;
	while (choice == 0)
	{
		ft_ps("Please choose between 1 and ");
		if (n_item_last_heap < 3)
			write(1, map->map[last_index] + '0', 1);
		else
			write(1, "3", 1);
		write(1, "\n", 1);
		input = gal(0, &size);
		if (!input)
			return (true);
		if (!size)
			ft_ps("Please input something\n");
		else
			choice = input[0] - '0';
		if (size > 1 || choice == 0 || choice > 3 || choice > map->map[last_index])
		{
			ft_ps(input);
			ft_ps(" - Invalid choice\n");
			choice = 0;
		}
		free(input);
	}
	map->map[last_index] -= choice;
	map->n_item -= choice;
	if (map->map[0] == 0)
		return (true);
	return (false);
}
