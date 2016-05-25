/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 20:48:17 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:48:05 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	int	id;

	id = ft_strlen(s);
	while (id >= 0)
	{
		if (s[id] == (char)c)
			return ((char *)&s[id]);
		id--;
	}
	return (NULL);
}
