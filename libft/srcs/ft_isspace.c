/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:19:22 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:40:31 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isspace(int c)
{
	unsigned char	check;

	check = (unsigned char)c;
	if (check == '\t' || check == '\n' || check == '\v' || check == '\f'
	|| check == '\r' || check == ' ')
		return (1);
	return (0);
}
