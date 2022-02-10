/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:47:25 by adelille          #+#    #+#             */
/*   Updated: 2022/01/29 12:59:04 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/gfd.h"

static bool	gfd_error(t_gfd *gfd, const int fd)
{
	if (fd != 0)
		close(fd);
	return (gfd_clear(&(gfd->data)));
}

bool	gfd(t_gfd *gfd, const int fd)
{
	ssize_t	res;
	t_gfdc	*current;

	gfd->n_part = 0;
	gfd->data = gfd_new();
	current = gfd->data;
	res = 1;
	while (res > 0)
	{
		current->part = (char *)malloc(sizeof(char) * GFD_BUFFER + 1);
		if (!current->part)
			return (gfd_error(gfd, fd));
		res = read(fd, current->part, GFD_BUFFER);
		if (res < 0)
			return (gfd_error(gfd, fd));
		current->part[res] = '\0';
		current->next = gfd_new();
		if (!current->next)
			return (gfd_error(gfd, fd));
		current = current->next;
		gfd->n_part++;
	}
	if (fd != 0)
		close(fd);
	return (true);
}
