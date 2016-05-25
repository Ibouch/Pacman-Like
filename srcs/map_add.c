/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 10:37:31 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/06 10:38:01 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

static void		add_node_in_list(t_map **alst, t_map *new_node)
{
	t_map	*begin;
	t_map	*tmp;

	begin = *alst;
	tmp = NULL;
	while ((begin != NULL) && ((ft_strcmp(new_node->file, begin->file)) > 0))
	{
		tmp = begin;
		begin = begin->next;
	}
	new_node->next = begin;
	if (tmp != NULL)
		tmp->next = new_node;
	else
		*alst = new_node;
}

static t_map	*new_map(char *map, char *file_name)
{
	int		i;
	t_map	*new;

	i = (-1);
	if ((new = (t_map *)ft_memalloc(sizeof(t_map))) == NULL)
		ft_error_system();
	((new->file = ft_strdup(file_name)) == NULL ? ft_error_system() : 0);
	((new->content = ft_strdup(map)) == NULL ? ft_error_system() : 0);
	new->hp = 3;
	while (++i < NB_GHOSTS)
		new->ghost.old_char[i] = ' ';
	new->next = NULL;
	return (new);
}

void			map_add(t_map **alst, char *map, char *file_name)
{
	t_map	*new_node;

	new_node = new_map(map, file_name);
	add_node_in_list(alst, new_node);
}
