/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:18:31 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/20 23:49:47 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_back(t_list **begin_lst, void *data, size_t size)
{
	t_list	*tmp;
	t_list	*new;

	new = ft_lstnew(data, size);
	if (*begin_lst != NULL)
	{
		tmp = *begin_lst;
		while ((*begin_lst)->next != NULL)
			*begin_lst = (*begin_lst)->next;
		(*begin_lst)->next = new;
		*begin_lst = tmp;
	}
	else
		*begin_lst = new;
}
