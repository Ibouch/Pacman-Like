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

static void	check_solid_option(t_env *e, int ac, char **av)
{
	if (ac == 3)
		(((ft_strcmp(av[2], "-s")) == 0) ? e->m->solid = TRUE
		: print_pacman_usage());
}

int			main(int ac, char **av)
{
	t_env	*e;

	if (ac != 2 && ac != 3)
		print_pacman_usage();
	if ((e = (t_env *)ft_memalloc(sizeof(t_env))) == NULL)
		ft_error_system();
	storage_map(e, av[1]);
	check_solid_option(e, ac, av);
	get_terminfo(e);
	run_pacman(e);
	map_lstdel(&(e->m));
	restore_term_default(&(e->term_default));
	exit(EXIT_SUCCESS);
}
