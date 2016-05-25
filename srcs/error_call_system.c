/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_call_system.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 12:24:14 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/06 12:24:17 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pacman.h>

void	error_call_system(char *s)
{
	ft_strcolor_fd("./ft_pacman: ", H_RED, 2, FALSE);
	ft_strcolor_fd(s, H_WHITE, 2, FALSE);
	ft_strcolor_fd(" system call has failed.", H_RED, 2, TRUE);
	exit(EXIT_FAILURE);
}
