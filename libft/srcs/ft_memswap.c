/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 18:08:35 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/11 03:05:35 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_memswap(void *a, void *b, size_t size)
{
	size_t			i;
	unsigned char	*bytes_a;
	unsigned char	*bytes_b;
	unsigned char	tmp;

	i = 0;
	bytes_a = (unsigned char *)a;
	bytes_b = (unsigned char *)b;
	while (i < size)
	{
		tmp = *(bytes_a + i);
		*(bytes_a + i) = *(bytes_b + i);
		*(bytes_b + i) = tmp;
		++i;
	}
}
