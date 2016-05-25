/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 15:19:50 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/25 15:19:53 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

static void	storage_file(t_map **addr, int fd, off_t size, char *file_name)
{
	char	map[size + 1];
	int		ret;
	int		tmp;

	ft_bzero((char *)map, (size + 1));
	ret = 0;
	while (((tmp = read(fd, (map + ret), size - ret)) < size) && tmp != (-1))
		ret += tmp;
	((tmp == (-1)) ? error_call_system("read") : 0);
	map_add(addr, map, file_name);
}

static char	*storage_path(char *path, char *name)
{
	size_t	end;
	char	*path_file;
	char	*tmp;

	end = (ft_strlen(path) - 1);
	if (path[end] == '/')
		path_file = ft_strjoin(path, name);
	else
	{
		tmp = ft_strjoin(path, "/");
		path_file = ft_strjoin(tmp, name);
		ft_strdel(&tmp);
	}
	if (path_file == NULL)
		ft_error_system();
	return (path_file);
}

void		get_dir_elem(t_env *e, DIR *directory, char *path)
{
	struct dirent	*elem;
	char			*new_path;
	int				fd;
	struct stat		st;

	while ((elem = readdir(directory)) != NULL)
	{
		new_path = storage_path(path, elem->d_name);
		if ((fd = open(new_path, O_RDONLY)) != (-1))
		{
			if ((fstat(fd, &st)) != 0)
				error_call_system("fstat");
			if (S_ISREG(st.st_mode) && elem->d_name[0] != '.')
			{
				++(e->nb_files);
				storage_file(&(e->m), fd, st.st_size, elem->d_name);
			}
			if ((close(fd)) != 0)
				error_call_system("close");
		}
		ft_strdel(&(new_path));
	}
}
