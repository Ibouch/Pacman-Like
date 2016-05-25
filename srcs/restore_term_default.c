/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_term_default.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 21:20:07 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/06 21:20:10 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

void	restore_term_default(t_termios *term_default)
{
	if ((tcsetattr(0, TCSADRAIN, term_default)) == (-1))
		error_call_system("tcsetattr");
	tputs(tgetstr("ve", NULL), 1, myputc);
	ft_putstr("\033[?1049l");
}
