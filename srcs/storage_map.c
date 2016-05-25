/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:09:48 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/12 17:29:58 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

static void	check_type_and_perm(mode_t mode, char *path)
{
	if (!S_ISDIR(mode))
	{
		ft_strcolor_fd("./ft_pacman: ", H_RED, 2, FALSE);
		ft_strcolor_fd(path, H_WHITE, 2, FALSE);
		ft_strcolor_fd(" is not a directory !", H_RED, 2, TRUE);
		exit(EXIT_FAILURE);
	}
	if ((access(path, X_OK)) == (-1))
	{
		ft_strcolor_fd("./ft_pacman: ", H_RED, 2, FALSE);
		ft_strcolor_fd(path, H_WHITE, 2, FALSE);
		ft_strcolor_fd(" permission denied.", H_RED, 2, TRUE);
		exit(EXIT_FAILURE);
	}
}

void		storage_map(t_env *e, char *path)
{
	struct stat	st;
	DIR			*directory;

	if ((access(path, F_OK)) == (-1))
	{
		ft_strcolor_fd("./ft_pacman: ", H_RED, 2, FALSE);
		ft_strcolor_fd(path, H_WHITE, 2, FALSE);
		ft_strcolor_fd(" no such file or directory.", H_RED, 2, TRUE);
		exit(EXIT_FAILURE);
	}
	if ((stat(path, &st)) != 0)
		error_call_system("stat");
	check_type_and_perm(st.st_mode, path);
	if ((directory = opendir(path)) == NULL)
		error_call_system("opendir");
	get_dir_elem(e, directory, path);
	if ((closedir(directory)) != 0)
		error_call_system("closedir");
}
