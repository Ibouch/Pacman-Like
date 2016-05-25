/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 05:31:34 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/11 18:38:51 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strsort(char **as, int len)
{
	int	i;
	int x;

	i = 0;
	x = (-1);
	if (!(*as) || len < 2)
		return (-1);
	while (i++ < (len - 1))
	{
		while (++x < (len - 1))
			if ((ft_strcmp(as[x], as[x + 1])) > 0)
				ft_strswap(&as[x], &as[x + 1]);
		x = (-1);
	}
	return (0);
}
