/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 18:34:20 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/12 13:44:19 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>
#include <time.h>

static void	build_map(t_map *m)
{
	int	y;

	m->nb_line = get_map_size(m->content, 0);
	m->nb_char = get_map_size(m->content, 1);
	m->map = (char **)ft_memalloc(sizeof(char *) * (m->nb_line + 1));
	if (m->map == NULL)
		ft_error_system();
	y = 0;
	while (y < m->nb_line)
	{
		if ((m->map[y] = ft_strnew(m->nb_char)) == NULL)
			ft_error_system();
		ft_strncpy(m->map[y], (m->content + (y * m->nb_char)), m->nb_char);
		++y;
	}
	storage_position(m);
	m->map[y] = NULL;
}

int			create_map(t_env *e, t_map *m)
{
	int	ret;
	int	i_time;

	build_map(m);
	print_map(m, e->solid);
	update_struct(&(e->term_update), 0);
	if ((tcsetattr(0, TCSADRAIN, &(e->term_update))) == (-1))
		error_call_system("tcsetattr");
	i_time = time(NULL);
	while (42)
	{
		ret = play_game(m, e->fast, &i_time);
		if (ret == LOST_HP)
		{
			--(m->hp);
			if (m->hp == 0)
				return (GAME_OVER);
			print_map(m, e->solid);
		}
		else if (ret != 0)
			return (ret);
	}
}
