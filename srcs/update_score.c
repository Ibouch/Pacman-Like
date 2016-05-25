/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 19:14:52 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/09 19:14:54 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

void	update_score(t_map *m, char c)
{
	char	*convert_score;
	int		i;

	if ((convert_score = ft_itoa(m->score)) == NULL)
		ft_error_system();
	i = 0;
	if (c == '.')
		m->score += 5;
	tputs(tgoto(tgetstr("cm", NULL), (m->nb_char + 13),
	calcul_pos(m->nb_line, 1)), 1, myputc);
	ft_strcolor_fd(convert_score, H_RED, 2, 1);
	ft_strdel(&(convert_score));
}
