/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 13:09:31 by adelille          #+#    #+#             */
/*   Updated: 2022/01/08 14:59:54 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

ssize_t	ft_ps(char *str)
{
	return (write(STDOUT, str, ft_strlen(str)));
}

ssize_t	ft_psc(char *str, char *color)
{
	return (write(STDOUT, color, ft_strlen(color))
		+ write(STDOUT, str, ft_strlen(str))
		+ write(STDOUT, DEF, ft_strlen(DEF)));
}

ssize_t	ft_pser(char *str)
{
	return (write(STDERR, str, ft_strlen(str)));
}

ssize_t	ft_pserc(char *str, char *color)
{
	return (write(STDERR, color, ft_strlen(color))
		+ write(STDERR, str, ft_strlen(str))
		+ write(STDERR, DEF, ft_strlen(DEF)));
}
