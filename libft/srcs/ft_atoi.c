/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 20:33:02 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:39:49 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *str)
{
	int		i;
	int		is_negv;
	int		result;

	i = 0;
	is_negv = 0;
	result = 0;
	while ((ft_isspace(str[i])) == 1)
		++i;
	if (str[i] == '+')
		++i;
	else if (str[i] == '-')
	{
		is_negv = 1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		++i;
	}
	return ((is_negv == 1) ? result * (-1) : result);
}
