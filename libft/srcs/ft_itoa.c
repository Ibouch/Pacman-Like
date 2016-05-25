/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:39:59 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:40:36 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_count_char(int n)
{
	int	nb_char;

	nb_char = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nb_char++;
		n = n * (-1);
	}
	while (n > 0)
	{
		n = n / 10;
		nb_char++;
	}
	return (nb_char);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		nb_char;
	int		nb;

	nb = n;
	if (nb == (-2147483648))
		return (ft_strdup("-2147483648"));
	nb_char = ft_count_char(n);
	str = ft_strnew(nb_char);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		n = n * (-1);
	str[nb_char--] = '\0';
	while (n >= 0 && nb_char >= 0)
	{
		str[nb_char] = (n % 10) + '0';
		n = n / 10;
		nb_char--;
	}
	if (nb < 0)
		str[0] = '-';
	return (str);
}
