/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 04:45:34 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/16 03:06:30 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lst_sort(t_list **alst, int (*f_cmp)())
{
	t_list	*begin_list;
	t_list	*tmp;
	void	*swap;

	begin_list = *alst;
	while (*alst != NULL)
	{
		tmp = begin_list;
		while (tmp->next != NULL)
		{
			if ((f_cmp(tmp->content, tmp->next->content)) > 0)
			{
				swap = tmp->content;
				tmp->content = tmp->next->content;
				tmp->next->content = swap;
			}
			tmp = tmp->next;
		}
		*alst = (*alst)->next;
	}
	*alst = begin_list;
}
