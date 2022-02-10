/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfd_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:06:55 by adelille          #+#    #+#             */
/*   Updated: 2022/01/29 12:37:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/gfd.h"

void	gfd_print(t_gfd gfd)
{
	ft_pnerc(gfd.n_part, "");
	write(STDERR, "\n", 1);
	while (gfd.data && gfd.data->part)
	{
		ft_ps(gfd.data->part);
		gfd.data = gfd.data->next;
	}
}
