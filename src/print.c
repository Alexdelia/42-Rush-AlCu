/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:24:54 by adelille          #+#    #+#             */
/*   Updated: 2022/02/12 18:55:28 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alcu.h"

void	print_map(t_map map)
{
	int j = 0;
	int len = 0;
	int diff = 0;
	int highest_len = 0;

	while (map.map[j]) // get the biggest line nb
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

void	print_winner(const int winner)
{
	if (winner == NO_WIN)
		return ;
	else if (winner == IA_WIN)
		ft_ps("\nYou lost, IA win\n");
	else if (winner == USER_WIN)
		ft_ps("\nGG! You win\n");
}

int	error(const char *str, const int ret)
{
	ft_pserc("ERROR\t", RED);
	if (!str)
		ft_pserc(str, C_RED);
	write(STDERR, "\n", 1);
	return (ret);
}
