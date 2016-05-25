/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:39:20 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:41:49 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *dst;
	char *source;

	dst = (char *)dest;
	source = (char *)src;
	if (source <= dst)
		while (n > 0)
		{
			*(dst + n - 1) = *(source + n - 1);
			n--;
		}
	else
		ft_memcpy(dst, source, n);
	return (dest);
}
