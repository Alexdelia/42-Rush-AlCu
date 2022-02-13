/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:24:54 by adelille          #+#    #+#             */
/*   Updated: 2022/02/13 16:38:49 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alcu.h"

static void	print_arrow(size_t len, const size_t highest)
{
	size_t	diff;
	size_t	i;

	ft_ps(C_GREEN);
	ft_ps(C_FLASH);
	diff = highest - len;
	while (diff-- > 0)
		write(1, " ", 1);
	ft_ps("\U00002570");
	while (len-- > 1)
		write(1, "--", 2);
	ft_ps("-\U0000256F\n");
	i = 0;
	while (i < highest)
	{
		write(1, " ", 1);
		i++;
	}
	ft_psc("\U000021E1", C_BOLD);
	write(1, "\n", 1);
}

static size_t	highest_len(const t_map map)
{
	size_t	highest;
	size_t	i;

	highest = 0;
	i = 0;
	while (map.map[i])
	{
		if (map.map[i] > highest)
			highest = map.map[i];
		i++;
	}
	return (highest);
}

void	print_map(const t_map map)
{
	size_t	len;
	size_t	highest;
	size_t	diff;
	size_t	i;

	highest = highest_len(map);
	i = 0;
	write(1, "\n", 1);
	ft_ps(C_BOLD);
	ft_ps(C_ITALIC);
	while (map.map[i])
	{
		write(1, " ", 1);
		len = map.map[i];
		diff = highest - len;
		while (diff-- > 0)
			write(1, " ", 1);
		while (len-- > 0)
			write(1, "| ", 2);
		write(1, "\n", 1);
		i++;
	}
	ft_ps(C_RESET);
	print_arrow(map.map[i - 1], highest);
	write(1, "\n", 1);
}

void	print_winner(const int winner)
{
	if (winner == NO_WIN)
		return ;
	ft_ps(C_BOLD);
	if (winner == IA_WIN)
		ft_psc("\n😈 You lost 😈\n", C_RED);
	else if (winner == USER_WIN)
		ft_psc("\n🎉 GG! You win 🎉\n", C_GREEN);
}

int	error(const char *str, const int ret)
{
	ft_pserc("ERROR\t", RED);
	if (str)
		ft_pserc(str, C_RED);
	write(STDERR, "\n", 1);
	return (ret);
}
