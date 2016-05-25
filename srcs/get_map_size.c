/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:50:10 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/10 13:50:13 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

int	get_map_size(char *map, int type)
{
	int	ret;
	int	id;

	ret = 0;
	id = 0;
	while (map[id] != '\0')
	{
		if (map[id] == '\n')
		{
			if (type == 1)
				return (++id);
			++ret;
		}
		++id;
	}
	return (ret);
}
