/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 20:56:14 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/21 00:04:03 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd(t_list **alst, void *data, size_t size)
{
	t_list	*new;

	new = ft_lstnew(data, size);
	if (*alst != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
	else
		*alst = new;
}
