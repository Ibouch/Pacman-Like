/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 22:28:52 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/23 22:28:53 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

static void	get_pos(t_map *m, int x, int y, int *gh)
{
	if (m->map[y][x] == 'P')
	{
		m->pacman.y = y;
		m->pacman.x = x;
		m->map[y][x] = 'c';
	}
	else if (m->map[y][x] == 'M')
	{
		m->ghost.y[*gh] = y;
		m->ghost.x[*gh] = x;
		m->ghost.init_y[*gh] = y;
		m->ghost.init_x[*gh] = x;
		++(*gh);
	}
}

void		storage_position(t_map *m)
{
	int	y;
	int	x;
	int	gh;

	y = 0;
	x = 0;
	gh = 0;
	while (m->map[y] != NULL)
	{
		while (m->map[y][x] != '\0')
		{
			get_pos(m, x, y, &gh);
			++x;
		}
		x = 0;
		++y;
	}
}
