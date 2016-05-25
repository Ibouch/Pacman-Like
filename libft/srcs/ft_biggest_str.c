/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_biggest_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:20:33 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:39:58 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_biggest_str(char *s1, char *s2, char *to_check)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_to_check;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_to_check = ft_strlen(to_check);
	if (len_to_check == len_s1)
		return ((len_to_check >= len_s2) ? 1 : 0);
	if (len_to_check == len_s2)
		return ((len_to_check >= len_s1) ? 1 : 0);
	return (0);
}
