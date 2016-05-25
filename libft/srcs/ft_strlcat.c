/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 20:45:18 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:46:55 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		n;
	size_t	i_src;
	size_t	i_dst;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size < len_dst)
		return (size + len_src);
	i_dst = len_dst;
	i_src = 0;
	n = (size - len_dst);
	while (--n > 0)
		dst[i_dst++] = src[i_src++];
	dst[i_dst] = '\0';
	return (len_dst + len_src);
}
