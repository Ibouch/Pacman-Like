/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 14:04:26 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/25 14:04:29 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

static struct s_key_event	g_key[4] =
{
	{{27, 91, 'A'}, 0, (-1)},
	{{27, 91, 'B'}, 0, 1},
	{{27, 91, 'C'}, 1, 0},
	{{27, 91, 'D'}, (-1), 0}
};

int	play_game(t_map *m, int *i_time)
{
	char			buf[5];
	int				i;
	int				ret;

	i = (-1);
	ret = 0;
	ft_strclr(buf);
	if ((read(0, buf, 3)) == (-1) || ESC)
		return (-1);
	while (++i < 4)
		if ((ft_strcmp(g_key[i].name, buf)) == 0)
			ret = move_pacman(m, (m->pacman.x + g_key[i].new_x),
			(m->pacman.y + g_key[i].new_y));
	if (ret == (-1))
		return (LOST_HP);
	(ret = ((check_time(i_time)) == 1) ? ghosts_ai(m) : ret);
	if (ret == (-1))
		return (LOST_HP);
	if (m->score == (m->total_piece * 5))
		return (LEVEL_UP);
	return (0);
}
