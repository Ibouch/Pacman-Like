/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:34:32 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:41:41 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			id;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)src;
	p2 = (unsigned char *)dest;
	id = 0;
	while (n--)
	{
		p2[id] = p1[id];
		id++;
	}
	return (p2);
}
