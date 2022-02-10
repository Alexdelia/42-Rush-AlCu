/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:00:35 by adelille          #+#    #+#             */
/*   Updated: 2021/12/18 13:07:19 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_pb(const bool w, const char *str)
{
	static char		buffer[PB_BUFFER];
	static size_t	index = 0;
	size_t			i;

	if (w == true)
	{
		write(1, buffer, index);
		return ;
	}
	i = 0;
	while (str[i])
	{
		buffer[index] = str[i];
		i++;
		index++;
		if (index >= PB_BUFFER)
		{
			write(1, buffer, index);
			index = 0;
		}
	}
}

void	ft_pb_s(const bool w, const char *str, const size_t size)
{
	static char		buffer[PB_BUFFER];
	static size_t	index = 0;
	size_t			i;

	if (w == true)
	{
		write(1, buffer, index);
		return ;
	}
	i = 0;
	while (i < size)
	{
		buffer[index] = str[i];
		i++;
		index++;
		if (index >= PB_BUFFER)
		{
			write(1, buffer, index);
			index = 0;
		}
	}
}

size_t	ft_pb_f(const bool w, const char *str)
{
	static char		buffer[PB_BUFFER];
	static size_t	index = 0;
	size_t			i;

	if (w == true)
	{
		write(1, buffer, index);
		return (ft_strlen(str));
	}
	i = 0;
	while (str[i])
	{
		buffer[index] = str[i];
		i++;
		index++;
		if (index >= PB_BUFFER)
		{
			write(1, buffer, index);
			index = 0;
		}
	}
	return (i);
}
