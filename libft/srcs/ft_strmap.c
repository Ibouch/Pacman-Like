/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:17:48 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:47:10 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	id;
	char	*ptr;

	id = 0;
	if ((!s) || (!f))
		return (NULL);
	ptr = ft_strdup(s);
	if (!ptr)
		return (NULL);
	while (s[id] != '\0')
	{
		ptr[id] = f(s[id]);
		id++;
	}
	return (ptr);
}
