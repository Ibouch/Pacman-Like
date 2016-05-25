/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 12:08:52 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/21 12:31:29 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lst_at(t_list *begin_lst, unsigned int id)
{
	t_list			*tmp;
	unsigned int	nb;

	if (id > 0)
	{
		tmp = begin_lst;
		nb = 0;
		while (tmp != NULL && ++nb < id)
			tmp = tmp->next;
		if (nb == id)
			return (tmp);
	}
	return (NULL);
}
