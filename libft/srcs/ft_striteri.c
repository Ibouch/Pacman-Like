/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:02:33 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:46:41 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	id;

	id = 0;
	if (s && f)
	{
		while (s[id] != '\0')
		{
			f(id, &s[id]);
			id++;
		}
	}
}
