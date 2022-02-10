/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:28:22 by adelille          #+#    #+#             */
/*   Updated: 2022/01/29 13:02:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFD_H
# define GFD_H

# include "libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# ifndef GFD_BUFFER
#  define GFD_BUFFER	280000
# elif GFD_BUFFER <= 0
#  define GFD_BUFFER	1
# endif

typedef struct s_file_data_chain
{
	char						*part;
	struct s_file_data_chain	*next;
}								t_gfdc;

typedef struct s_file_data
{
	t_gfdc	*data;
	size_t	n_part;
}			t_gfd;

bool	gfd(t_gfd *gfd, const int fd);

t_gfdc	*gfd_new(void);
bool	gfd_addback(t_gfdc **alst, t_gfdc *new);
t_gfdc	*gfd_last(t_gfdc *gfdc);

void	gfd_print(t_gfd gfd);

bool	gfd_clear(t_gfdc **gfdc);

#endif
