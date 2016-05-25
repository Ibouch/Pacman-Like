/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ghosts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:19:49 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/22 19:26:40 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

static void	overwrite_last_pos(t_map *m, int i)
{
	tputs(tgoto(tgetstr("cm", NULL), m->ghost.x[i], m->ghost.y[i]), 1, myputc);
	m->map[m->ghost.y[i]][m->ghost.x[i]] = m->ghost.old_char[i];
	if (m->ghost.old_char[i] == '.')
		ft_strcolor_fd(".", H_GREEN, 2, FALSE);
	else
		ft_putchar_fd(m->ghost.old_char[i], 2);
}

int			move_ghosts(t_map *m, int x[NB_GHOSTS], int y[NB_GHOSTS])
{
	int	i;

	i = (-1);
	while (++i < NB_GHOSTS)
	{
		if (m->map[y[i]][x[i]] == 'c')
			return (-1);
		if (m->map[y[i]][x[i]] != '#' && m->map[y[i]][x[i]] != 'M')
		{
			overwrite_last_pos(m, i);
			m->ghost.old_char[i] = m->map[y[i]][x[i]];
			tputs(tgoto(tgetstr("cm", NULL), x[i], y[i]), 1, myputc);
			m->map[y[i]][x[i]] = 'M';
			m->ghost.x[i] = x[i];
			m->ghost.y[i] = y[i];
			ft_strcolor_fd("M", H_RED, 2, FALSE);
		}
		if (m->map[y[i]][x[i]] == 'M')
			if (i > 0)
				m->ghost.old_char[i] = m->ghost.old_char[i - 1];
	}
	return (0);
}
