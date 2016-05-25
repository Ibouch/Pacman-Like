/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 12:15:50 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/21 12:30:29 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_lst_size(t_list *begin_lst)
{
	t_list	*tmp;
	int		nb;

	tmp = begin_lst;
	nb = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		++nb;
	}
	return (nb);
}
