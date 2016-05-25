/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:09:53 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:47:20 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	char			*tmp;
	unsigned int	id;

	id = 0;
	if ((!s) || (!f))
		return (NULL);
	ptr = ft_strdup(s);
	if (!ptr)
		return (NULL);
	tmp = ptr;
	while (ptr[id])
	{
		ptr[id] = f(id, s[id]);
		id++;
	}
	return (tmp);
}
