/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:21:57 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:46:50 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		len;

	if ((!s1) || (!s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = ft_strnew(len);
	if (!result)
		return (NULL);
	result = ft_strcpy(result, s1);
	ft_strcpy(&result[ft_strlen(s1)], s2);
	return ((!result) ? NULL : result);
}
