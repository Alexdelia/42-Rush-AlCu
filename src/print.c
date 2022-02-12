/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:24:54 by adelille          #+#    #+#             */
/*   Updated: 2022/02/12 12:29:13 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alcu.h"

void	print_winner(const int winner)
{
	if (winner == NO_WIN)
		return ;
	else if (winner == IA_WIN)
		ft_ps("\nYou lost, IA win\n");
	else if (winner == USER_WIN)
		ft_ps("\nGG! You win\n");
}
