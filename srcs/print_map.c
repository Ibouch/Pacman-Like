/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 12:53:48 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/07 12:53:51 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

static void	print_hp(t_map *m)
{
	int	i;

	i = 0;
	tputs(tgoto(tgetstr("cm", NULL), (m->nb_char + 5),
	calcul_pos(m->nb_line, 1) + 1), 1, myputc);
	while (i++ != m->hp)
		ft_strcolor_fd("❤ ", H_RED, 2, 0);
}

static void	get_ghosts_position(t_map *m)
{
	int	gh;

	gh = 0;
	while (gh < NB_GHOSTS)
	{
		m->map[m->ghost.y[gh]][m->ghost.x[gh]] = m->ghost.old_char[gh];
		m->ghost.x[gh] = m->ghost.init_x[gh];
		m->ghost.y[gh] = m->ghost.init_y[gh];
		m->map[m->ghost.y[gh]][m->ghost.x[gh]] = 'M';
		++gh;
	}
}

static void	print_data(t_map *m)
{
	char	*convert_score;
	char	*convert_level;

	if ((convert_score = ft_itoa(m->score)) == NULL)
		ft_error_system();
	if ((convert_level = ft_itoa(m->level)) == NULL)
		ft_error_system();
	tputs(tgoto(tgetstr("cl", NULL), 0, 0), 1, myputc);
	tputs(tgoto(tgetstr("cm", NULL), (m->nb_char + 5),
	calcul_pos(m->nb_line, 0)), 1, myputc);
	ft_strcolor_fd("LEVEL : ", H_GREEN, 2, 0);
	ft_strcolor_fd(convert_level, H_GREEN, 2, 1);
	tputs(tgoto(tgetstr("cm", NULL), (m->nb_char + 5),
	calcul_pos(m->nb_line, 1)), 1, myputc);
	ft_strcolor_fd("SCORE : ", H_RED, 2, 0);
	ft_strcolor_fd(convert_score, H_RED, 2, 1);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, myputc);
	ft_strdel(&(convert_score));
	ft_strdel(&(convert_level));
}

static void	print_map_elem(char c, t_bool solid)
{
	if (c == 'c')
		ft_strcolor_fd("c", H_YELLOW, 2, FALSE);
	else if (c == '#')
	{
		(solid == TRUE) ? ft_putstr_fd(BKI_BLUE, 2) : 0;
		ft_strcolor_fd("#", H_BLUE, 2, FALSE);
	}
	else if (c == '.')
		ft_strcolor_fd(".", H_GREEN, 2, FALSE);
	else if (c == 'M')
		ft_strcolor_fd("M", H_RED, 2, FALSE);
	else
		ft_putchar_fd(c, 2);
}

void		print_map(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	print_data(m);
	get_ghosts_position(m);
	while (m->map[y] != NULL)
	{
		while (m->map[y][x] != '\0')
		{
			print_map_elem(m->map[y][x], m->solid);
			++x;
		}
		x = 0;
		++y;
	}
	print_hp(m);
}
