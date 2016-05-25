/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghosts_ai.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:19:34 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/12 13:44:05 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

void	determine_possibility(t_map *m, int *x, int *y)
{
	int	max_y;
	int	max_x;

	max_y = (m->nb_line - 1);
	max_x = (m->nb_char - 2);
	if (m->map[*y][*x] == '#')
	{
		fprintf(stderr, "IMPOSSSIBLE\n");}
}

int	ghosts_ai(t_map *m)
{
	int	i;
	int	x[NB_GHOSTS];
	int	y[NB_GHOSTS];

	i = (-1);
	while (++i < NB_GHOSTS)
	{
		x[i] = m->ghost.x[i];
		y[i] = m->ghost.y[i];
		while (m->map[y[i]][x[i]] == 'M' || m->map[y[i]][x[i]] == '#')
		{
			x[i] = m->ghost.x[i];
			y[i] = m->ghost.y[i];
			x[i] += (arc4random() % 3) - 1;
			y[i] += (arc4random() % 3) - 1;
			tputs(tgoto(tgetstr("cm", NULL), 0, m->nb_line + 5), 1, myputc);
			fprintf(stderr, "new x: %d new y: %d\n", x[i], y[i]);
		}
		/*
		x[i] = m->ghost.x[i];
		y[i] = m->ghost.y[i];
		if (m->pacman.y >= m->ghost.y[i])
		{
			if (m->pacman.y == m->ghost.y[i])
			{
				if (m->pacman.x == m->ghost.x[i])
					return (-1);
				x[i] = ((m->pacman.x > m->ghost.x[i]) ? ++x[i] : --x[i]);
			}
			else
			{
				++y[i];
				//determine_possibility(m, &(x[i]), &(y[i]));
			}
		}
		else
			--y[i];
		*/
	}
	return (move_ghosts(m, x, y));
}
