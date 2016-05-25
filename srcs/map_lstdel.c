/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 00:22:24 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/08 00:22:26 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

void	map_lstdel(t_map **alst)
{
	t_map	*tmp;

	while (*alst != NULL)
	{
		ft_strdel(&((*alst)->file));
		ft_strdel(&((*alst)->content));
		ft_tabdel((*alst)->map);
		tmp = *alst;
		*alst = (*alst)->next;
		ft_memdel((void **)&tmp);
	}
}
