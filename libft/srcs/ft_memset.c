/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:36:02 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:41:53 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*pt;

	i = 0;
	pt = (unsigned char *)b;
	while (len--)
		pt[i++] = (unsigned char)c;
	return (pt);
}
