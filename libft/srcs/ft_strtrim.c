/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:42:15 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:48:34 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	occu1;
	size_t	occu2;

	i = 0;
	occu1 = 0;
	occu2 = 0;
	if (!s)
		return (NULL);
	while (((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')) && (s[i] != 0))
		i++;
	if (s[i] == '\0')
		return (ft_memalloc(1));
	occu1 = i;
	i = ft_strlen(s) - 1;
	while (((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')) && (i != 0))
		i--;
	occu2 = (i == (ft_strlen(s) - 1) ? 0 : (ft_strlen(s) - i) - 1);
	return (ft_strsub(s, occu1, ft_strlen(s) - (occu1 + occu2)));
}
