/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pacman.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 20:59:01 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/12 17:30:37 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

static void	invalid_map(t_termios *term_default)
{
	restore_term_default(term_default);
	ft_strcolor_fd("./ft_pacman: Invalid map.", H_RED, 2, TRUE);
	ft_putendl_fd("Segmentation fault: 11", 2);
	exit(EXIT_FAILURE);
}

static int	check_return_value(int value)
{
	tputs(tgoto(tgetstr("cl", NULL), 0, 0), 1, myputc);
	if (value == (-1))
		return (-1);
	else if (value == GAME_OVER)
	{
		ft_strcolor_fd("[GAME OVER] !", H_RED, 2, 1);
		sleep(2);
		return (-1);
	}
	return (0);
}

void		run_pacman(t_env *e)
{
	int		lvl;
	int		i;
	t_map	*begin;

	lvl = select_level(e);
	i = 0;
	begin = e->m;
	if (lvl != (-1))
	{
		while (begin != NULL && ++i < lvl)
			begin = begin->next;
		while (begin != NULL)
		{
			begin->level = lvl;
			if ((begin->total_piece = verify_map(begin->content)) == (-1))
				invalid_map(&(e->term_default));
			i = create_map(&(e->term_update), begin);
			if ((check_return_value(i)) == (-1))
				break ;
			++lvl;
			begin = begin->next;
		}
	}
}
