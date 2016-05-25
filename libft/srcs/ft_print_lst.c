/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 03:09:37 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/24 23:08:45 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_print_lst(t_list *lst, int fd)
{
	while (lst != NULL)
	{
		ft_putendl_fd((char *)lst->content, fd);
		lst = lst->next;
	}
}
