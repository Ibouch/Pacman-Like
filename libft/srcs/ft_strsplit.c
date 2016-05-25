/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:36:43 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:48:26 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	size_t	ft_countword(char const *s, char c)
{
	size_t	id;
	size_t	nb_word;

	id = 0;
	nb_word = 0;
	while (s[id])
	{
		while ((s[id] == c) && (s[id]))
			id++;
		if (s[id] != '\0')
		{
			while ((s[id] != c) && (s[id]))
				id++;
			nb_word++;
		}
	}
	return (nb_word);
}

static	void	ft_wordlen(const char *s, char c, size_t size[2])
{
	size_t	len;
	size_t	id;

	len = 0;
	id = size[0];
	while ((s[id] == c) && (s[id]))
		id++;
	size[0] = id;
	if (s[id] != '\0')
		while ((s[id] != c) && (s[id]))
		{
			len++;
			id++;
		}
	size[1] = len;
}

static	char	*ft_addword(char const *s, char c, size_t size[2])
{
	char	*word;

	ft_wordlen(s, c, size);
	word = ft_strsub(s, size[0], size[1]);
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	size[2];
	size_t	id;
	size_t	x;

	if (s == NULL)
		return (NULL);
	x = 0;
	id = 0;
	size[1] = 0;
	tab = (char **)malloc(sizeof(char *) * ft_countword(s, c) + 1);
	if (!tab)
		return (NULL);
	while (x < ft_countword(s, c))
	{
		while ((s[id] == c) && (s[id]))
			id++;
		size[0] = id;
		if (s[id])
			tab[x++] = ft_addword(s, c, size);
		id = id + size[1];
	}
	tab[x] = NULL;
	return (tab);
}
