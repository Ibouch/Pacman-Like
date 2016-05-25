/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 20:08:03 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:40:43 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*to_free;

	tmp = *alst;
	if (tmp)
	{
		while (tmp)
		{
			del(tmp->content, tmp->content_size);
			to_free = tmp;
			tmp = tmp->next;
			free(to_free);
		}
		*alst = NULL;
	}
}
