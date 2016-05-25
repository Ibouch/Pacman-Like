/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 17:33:26 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:41:00 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *result;

	tmp = (t_list*)malloc(sizeof(*tmp));
	if (tmp == NULL)
		return (NULL);
	tmp = f(lst);
	result = tmp;
	if (lst)
		while (lst->next)
		{
			tmp->next = (t_list*)malloc(sizeof(*tmp));
			lst = lst->next;
			tmp->next = f(lst);
			tmp = tmp->next;
		}
	return (result);
}
