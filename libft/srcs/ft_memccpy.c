/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:48:04 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:41:24 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)src;
	p2 = (unsigned char *)dest;
	while (n--)
	{
		p2[i] = p1[i];
		if (p1[i] == (unsigned char)c)
			return (&p2[i + 1]);
		i++;
	}
	return (NULL);
}
