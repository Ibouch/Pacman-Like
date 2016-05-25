/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:39:15 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:47:43 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if ((!s1) || (!s2))
		return ((int)NULL);
	return (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
}
