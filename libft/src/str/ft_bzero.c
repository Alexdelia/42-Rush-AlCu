/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:56:45 by adelille          #+#    #+#             */
/*   Updated: 2021/12/12 16:58:33 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_bzero(void *s, size_t n)
{
	register char	*i;

	if (!s)
		return ;
	i = s;
	while (n >= sizeof(uint64_t))
	{
		*((uint64_t *)i) = 0;
		i += sizeof(uint64_t);
		n -= sizeof(uint64_t);
	}
	if (n >= sizeof(uint32_t))
	{
		*((uint32_t *)i) = 0;
		i += sizeof(uint32_t);
		n -= sizeof(uint32_t);
	}
	if (n >= sizeof(uint16_t))
	{
		*((uint16_t *)i) = 0;
		i += sizeof(uint16_t);
		n -= sizeof(uint16_t);
	}
	if (n)
		*i = 0;
}
