/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:12:32 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:47:57 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	id_str;
	size_t	id_storage;
	size_t	id_find;

	id_storage = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while ((str[id_storage] != '\0') && (id_storage < n))
	{
		id_find = 0;
		while ((str[id_storage] != to_find[0]) && (str[id_storage])
				&& id_storage < n)
			id_storage++;
		if (str[id_storage] == '\0')
			return (NULL);
		id_str = id_storage;
		while (to_find[id_find++] == str[id_str] && id_str < n)
		{
			id_str++;
			if (to_find[id_find] == '\0')
				return ((char *)&str[id_storage]);
		}
		id_storage++;
	}
	return (NULL);
}
