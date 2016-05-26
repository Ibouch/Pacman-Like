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

static void	check_reverse(t_map *m, int *x, int *y, int i)
{
	if (*x < 0 || *x > (m->nb_char - 2))
	{
		if (*x < 0 && m->map[*y][(m->nb_char - 2)] != '#')
			*x = (m->nb_char - 2);
		else if (*x > (m->nb_char - 2) && m->map[*y][0] != '#')
			*x = 0;
		else
			*x = m->ghost.x[i];
	}
	if (*y < 0 || *y > (m->nb_line - 1))
	{
		if (*y < 0 && m->map[(m->nb_line - 1)][*x] != '#')
			*y = (m->nb_line - 1);
		else if (*y > (m->nb_line - 1) && m->map[0][*x] != '#')
			*y = 0;
		else
			*y = m->ghost.y[i];
	}
}

static void	debug(int *x, int *y)
{
	int	rand_x;
	int	rand_y;

	rand_x = 0;
	rand_y = 0;
	while (rand_x + rand_y != (-1) && rand_x + rand_y != 1)
	{
		rand_x = (arc4random() % 3) - 1;
		rand_y = (arc4random() % 3) - 1;
	}
	*x += rand_x;
	*y += rand_y;
}

int			ghosts_ai(t_map *m)
{
	int	i;
	int	x;
	int	y;

	i = (-1);
	while (++i < NB_GHOSTS)
	{
		x = m->ghost.x[i];
		y = m->ghost.y[i];
		debug(&x, &y);
		check_reverse(m, &x, &y, i);
		if ((move_ghosts(m, x, y, i)) == (-1))
			return (-1);
	}
	return (0);
}
