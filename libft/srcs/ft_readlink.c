/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 23:31:56 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 01:12:40 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_readlink(char *path, off_t size)
{
	char	*lnk_name;
	ssize_t	len;

	if ((lnk_name = ft_strnew(size)) == NULL)
		ft_error_system();
	if ((len = readlink(path, lnk_name, size)) == (-1))
	{
		ft_putstr_fd("Error: ", 2);
		perror(path);
		ft_strdel(&lnk_name);
		return (NULL);
	}
	lnk_name[len] = '\0';
	return (lnk_name);
}
