/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 14:39:53 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/12 16:30:55 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

static void	print_level(t_map *m)
{
	int	i;

	i = 1;
	while (m != NULL)
	{
		ft_strcolor_fd("(", H_GREEN, 2, FALSE);
		ft_putnbr_fd(i, 2);
		ft_strcolor_fd(")", H_GREEN, 2, FALSE);
		ft_strcolor_fd("\t\t- ", H_BLACK, 2, FALSE);
		ft_strcolor_fd(m->file, H_WHITE, 2, TRUE);
		write(2, "\n", 1);
		++i;
		m = m->next;
	}
	ft_strcolor_fd("(ESC)", H_GREEN, 2, FALSE);
	ft_strcolor_fd("\t\t- ", H_BLACK, 2, FALSE);
	ft_strcolor_fd("Quit the game", H_WHITE, 2, TRUE);
}

static void	print_banner(void)
{
	int		fd;
	char	buf[477];

	if ((fd = open("banner.pacman", O_RDONLY)) != (-1))
	{
		if ((read(fd, buf, 476)) == 476)
		{
			buf[476] = '\0';
			ft_strcolor_fd(buf, H_YELLOW, 2, TRUE);
		}
		close(fd);
	}
}

int			select_level(t_env *e)
{
	char	buf[2];
	char	*tmp;
	char	max_level;

	print_banner();
	print_level(e->m);
	if ((tmp = ft_itoa(e->nb_files)) == NULL)
		ft_error_system();
	max_level = tmp[0];
	ft_strdel(&tmp);
	while (42)
	{
		ft_strclr(buf);
		if ((read(0, buf, 2)) <= 0)
			return (-1);
		if (ESC)
			return (-1);
		if (IS_LEVEL)
			return (buf[0] - '0');
	}
}
