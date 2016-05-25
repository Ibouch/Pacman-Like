/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pacman.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:06:56 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/11 17:06:59 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

static void	overwrite_last_pos(char **map, int x, int y)
{
	tputs(tgoto(tgetstr("cm", NULL), x, y), 1, myputc);
	map[y][x] = ' ';
	ft_putchar_fd(' ', 2);
}

static void	teleport_dimension(t_map *m, int *x, int *y)
{
	if (*x < 0 || *x > (m->nb_char - 2))
	{
		if (*x < 0 && m->map[*y][(m->nb_char - 2)] != '#')
			*x = (m->nb_char - 2);
		else if (*x > (m->nb_char - 2) && m->map[*y][0] != '#')
			*x = 0;
		else
			*x = m->pacman.x;
	}
	if (*y < 0 || *y > (m->nb_line - 1))
	{
		if (*y < 0 && m->map[(m->nb_line - 1)][*x] != '#')
			*y = (m->nb_line - 1);
		else if (*y > (m->nb_line - 1) && m->map[0][*x] != '#')
			*y = 0;
		else
			*y = m->pacman.y;
	}
}

int			move_pacman(t_map *m, int x, int y)
{
	teleport_dimension(m, &x, &y);
	if (m->map[y][x] == 'M')
		return (-1);
	if (m->map[y][x] != '#')
	{
		overwrite_last_pos(m->map, m->pacman.x, m->pacman.y);
		update_score(m, m->map[y][x]);
		tputs(tgoto(tgetstr("cm", NULL), x, y), 1, myputc);
		ft_strcolor_fd("c", H_YELLOW, 2, FALSE);
		m->map[y][x] = 'c';
		m->pacman.x = x;
		m->pacman.y = y;
	}
	return (0);
}
