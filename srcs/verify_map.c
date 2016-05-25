/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:19:06 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/06 17:42:33 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

static int	parse_map(char c, int *nb_player, int *total_piece, int *nb_ghost)
{
	if (c == 'P')
		++(*nb_player);
	else if (c == '.')
		++(*total_piece);
	else if (c == 'M')
		++(*nb_ghost);
	else if (c != '#' && c != '\n' && c != ' ')
		return (-1);
	return (0);
}

static int	check_line(char *map, int i, int *n)
{
	int	nb_char;

	nb_char = get_map_size(map, 1);
	if (nb_char != (*n = (i == (nb_char - 1)) ? *n + 1 : *n))
		return (-1);
	*n = 0;
	return (0);
}

int			verify_map(char *map)
{
	int	i;
	int	n;
	int	nb_player;
	int	nb_piece;
	int	nb_ghost;

	i = 0;
	n = 0;
	nb_player = 0;
	nb_piece = 0;
	nb_ghost = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			if ((check_line(map, i, &n)) == (-1))
				return (-1);
		if ((parse_map(map[i], &nb_player, &nb_piece, &nb_ghost)) == (-1))
			return (-1);
		++n;
		++i;
	}
	return (((nb_player != 1 || nb_ghost != NB_GHOSTS) || nb_piece <= 0)
	? (-1) : nb_piece);
}
