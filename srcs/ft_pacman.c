/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pacman.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 15:55:31 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/04 17:22:41 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

static void	print_pacman_usage(void)
{
	ft_strcolor_fd("usage: ./ft_pacman [path ...] [-s]", H_RED, 2, TRUE);
	exit(EXIT_FAILURE);
}

static void	check_option(t_env *e, int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		if (av[2][i] == '-')
			while (av[2][++i] != '\0')
			{
				if (av[2][i] == 's')
					e->solid = TRUE;
				else if (av[2][i] == 'f')
					e->fast = TRUE;
				else
					print_pacman_usage();
			}
	}
}

int			main(int ac, char **av)
{
	t_env	*e;

	if (ac != 2 && ac != 3)
		print_pacman_usage();
	if ((e = (t_env *)ft_memalloc(sizeof(t_env))) == NULL)
		ft_error_system();
	storage_map(e, av[1]);
	check_option(e, ac, av);
	get_terminfo(e);
	run_pacman(e);
	map_lstdel(&(e->m));
	restore_term_default(&(e->term_default));
	exit(EXIT_SUCCESS);
}
