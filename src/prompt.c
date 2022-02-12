/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:15:05 by adelille          #+#    #+#             */
/*   Updated: 2022/02/12 18:42:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alcu.h"

static size_t	last_heap(size_t *map)
{
	size_t	i;

	i = 0;
	while (map[i] != 0)
		i++;
	if (i == 0)
		return (0);
	return (i - 1);
}

static void	prompt_message(const size_t max)
{
	char	c;

	ft_ps("Please choose between 1 and ");
	if (max < 3)
	{
		c = max + '0';
		write(1, &c, 1);
	}
	else
		write(1, "3", 1);
	write(1, "\n", 1);
}

static size_t	check_input(const char *input, const size_t max)
{
	size_t	i;
	size_t	ret;

	ret = 0;
	i = 0;
	while (input[i] && input[i] != '\n')
	{
		if (!(input[i] > '0' && input[i] < '9'))
			return ((write(1, input, ft_strlen(input) - 1)
					+ ft_pser(" - Invalid input\t(Only digits)\n")) * 0);
		ret = ret * 10 + (input[i] - '0');
		if (ret > UINT_MAX)
			return ((write(1, input, ft_strlen(input) - 1)
					+ ft_pser(" - invalid input\t(input > uint_max)\n")) * 0);
		i++;
	}
	if (ret == 0 || ret > 3 || ret > max)
		return ((write(1, input, ft_strlen(input) - 1)
				+ ft_pser(" - invalid input\n")) * 0);
	return (ret);
}

bool	prompt(t_map *map)
{
	char	*input;
	size_t	size;
	size_t	choice;
	size_t	last_index;

	last_index = last_heap(map->map);
	choice = 0;
	while (choice == 0)
	{
		prompt_message(map->map[last_index]);
		input = gal(STDIN, &size);
		if (!input)
			return (true);
		if (!size)
			return (ft_ps("Please enter map from stdin directly\n")); // tmp
		choice = check_input(input, map->map[last_index]);
		free(input);
		input = NULL;
	}
	map->map[last_index] -= choice;
	map->n_item -= choice;
	if (map->map[0] == 0)
	{
		map->winner = IA_WIN;
		return (true);
	}
	return (false);
}
