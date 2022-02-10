/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:54:03 by adelille          #+#    #+#             */
/*   Updated: 2022/01/29 12:37:31 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/gfd.h"

t_gfdc	*gfd_new(void)
{
	t_gfdc	*new;

	new = (t_gfdc *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->part = NULL;
	new->next = NULL;
	return (new);
}

bool	gfd_addback(t_gfdc **alst, t_gfdc *new)
{
	t_gfdc	*last;

	if (!new || !alst)
		return (false);
	if (*alst)
	{
		last = gfd_last(*alst);
		last->next = new;
	}
	else
		*alst = new;
	return (true);
}

t_gfdc	*gfd_last(t_gfdc *gfdc)
{
	while (gfdc)
	{
		if (!gfdc->next)
			return (gfdc);
		gfdc = gfdc->next;
	}
	return (gfdc);
}

bool	gfd_clear(t_gfdc **gfdc)
{
	t_gfdc	*tmp;

	if (!gfdc || !*gfdc)
		return (false);
	while (*gfdc)
	{
		tmp = (*gfdc)->next;
		free((*gfdc)->part);
		free(*gfdc);
		*gfdc = tmp;
	}
	return (false);
}
