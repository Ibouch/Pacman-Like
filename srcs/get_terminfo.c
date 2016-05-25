/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_terminfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:00:21 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/22 20:56:17 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

void	update_struct(struct termios *term, int vmin)
{
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = vmin;
	term->c_cc[VTIME] = 0;
}

void	get_terminfo(t_env *e)
{
	if ((tgetent((char *)NULL, getenv("TERM"))) != 1)
		error_call_system("tgetent");
	if ((tcgetattr(0, &(e->term_default))) == (-1))
		error_call_system("tcgetattr");
	if ((tcgetattr(0, &(e->term_update))) == (-1))
		error_call_system("tcgetattr");
	update_struct(&(e->term_update), 1);
	if ((tcsetattr(0, TCSADRAIN, &(e->term_update))) == (-1))
		error_call_system("tcsetattr");
	tputs(tgetstr("vi", NULL), 1, myputc);
	ft_putstr_fd("\033[?1049h\033[H", 2);
}
