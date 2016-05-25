/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 14:04:38 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/25 14:04:43 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>
#include <time.h>

int	check_time(int *i_time)
{
	if ((*i_time + TIMEOUT) == time(NULL))
	{
		(*i_time) += TIMEOUT;
		return (1);
	}
	else
		return (0);
}
