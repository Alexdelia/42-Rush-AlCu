/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:07:50 by adelille          #+#    #+#             */
/*   Updated: 2021/12/18 15:55:41 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

bool	ft_pb_oms(const bool w, const char *str, const size_t size)
{
	static char		*buffer = NULL;
	static size_t	index = 0;

	if (size > PB_BUFFER / 4)
		return (write(1, str, size));
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * (PB_BUFFER));
		if (!buffer)
			return (false);
	}
	if (size + index > PB_BUFFER || w == true)
	{
		write(1, buffer, index);
		index = 0;
		if (w == true)
		{
			free(buffer);
			buffer = NULL;
			return (true);
		}
	}
	index += ft_strocpy(&buffer[index], str, size);
	return (true);
}

bool	ft_pb_omsa(const bool w, const char *str, const size_t size)
{
	static char		*buffer = NULL;
	static size_t	index = 0;

	if (size >= 1600)
		return (write(1, str, size));
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * (PB_BUFFER));
		if (!buffer)
			return (false);
	}
	if (size + index > PB_BUFFER || w == true)
	{
		write(1, buffer, index);
		index = 0;
		if (w == true)
		{
			free(buffer);
			buffer = NULL;
			return (true);
		}
	}
	index += ft_strocpy(&buffer[index], str, size);
	return (true);
}
