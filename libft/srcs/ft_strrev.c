/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 13:09:57 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/11 03:06:49 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strrev(char *str)
{
	size_t	start;
	size_t	end;
	int		n;

	start = 0;
	end = ft_strlen(str) - 1;
	n = ft_strlen(str) / 2;
	while ((int)start < n)
		ft_memswap(&str[start++], &str[end--], 1);
}
