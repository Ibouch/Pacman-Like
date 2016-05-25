/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:30:19 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/10 17:30:22 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

int	calcul_pos(int nb_line, int obj)
{
	int	level_pos;
	int	score_pos;

	level_pos = ((nb_line - 1) / 2);
	score_pos = (nb_line / 2);
	if ((obj == 1) && (score_pos == level_pos))
		return (++score_pos);
	return ((obj == 0) ? level_pos : score_pos);
}
