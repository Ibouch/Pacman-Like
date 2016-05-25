/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 18:12:39 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/26 23:16:32 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static	int	ft_check(char *str, int size)
{
	int	i;
	int	max;

	i = (-1);
	max = (size > 0) ? size : BUFF_SIZE;
	while (++i < max)
	{
		if (str[i] == '\0')
			return (2);
		else if (str[i] == DE)
			return (1);
	}
	return (0);
}

static char	*ft_storage_rest(char *str, int max)
{
	int		i;
	char	*rest;
	int		start;

	i = (-1);
	while (str[++i] != DE)
		;
	start = i + 1;
	i = 0;
	rest = ft_strnew(max);
	rest[0] = '\0';
	if (str[start] != '\0')
	{
		while ((start < max) && (str[start] != '\0'))
			rest[i++] = str[start++];
		*(rest + i) = '\0';
	}
	return (rest);
}

static int	ft_storage_in_line(char *str, char **line, int max, int edl)
{
	int		i;
	char	*line_tmp;
	char	*tmp;

	i = (-1);
	line_tmp = ft_strdup((*line));
	free(*line);
	if (edl == 1)
	{
		while (str[++i] != DE)
			;
		max = i;
		i = (-1);
	}
	tmp = (edl == 1) ? ft_strnew(max + 1) : ft_strnew(max);
	while (++i < max)
		*(tmp + i) = *(str + i);
	*(tmp + i) = '\0';
	(*line) = ft_strjoin(line_tmp, tmp);
	free(line_tmp);
	free(tmp);
	return (0);
}

static int	ft_traiting_value_rest(char *rest, char *buf, char **line)
{
	int		len;
	int		edl;
	char	*r_tmp;

	if (rest && rest[0] != '\0')
	{
		len = ft_strlen(rest);
		edl = ft_check(rest, len);
		ft_storage_in_line(rest, line, len, edl);
		if (edl == 1)
		{
			r_tmp = ft_strdup(rest);
			ft_strclr(rest);
			ft_strcpy(rest, ft_storage_rest(r_tmp, len));
			free(r_tmp);
			return (1);
		}
		rest[0] = '\0';
	}
	ft_bzero(buf, BUFF_SIZE);
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char	*rest;
	char		buf[BUFF_SIZE];
	int			rd;

	if (line == NULL || (fd < 0 || BUFF_SIZE < 1))
		return (-1);
	*line = (char *)ft_memalloc(1);
	if ((ft_traiting_value_rest(rest, buf, line)) == 1)
		return (1);
	while (((rd = read(fd, buf, BUFF_SIZE)) > 0) && ((ft_check(buf, 0)) == 0))
		ft_storage_in_line(buf, line, rd, 0);
	if (rd == (-1))
		return (-1);
	if ((rd == 0 && (!rest || rest[0] == '\0')) && *line[0] == '\0')
		return (0);
	if (rest && rest[0] != '\0')
		ft_storage_in_line(rest, line, rd, (ft_check(rest, 0)));
	if ((ft_check(buf, 0)) == 1)
	{
		ft_storage_in_line(buf, line, rd, 1);
		rest = ft_storage_rest(buf, rd);
	}
	if (((ft_check(buf, 0)) == 2) && (rd > 0))
		ft_storage_in_line(buf, line, rd, 0);
	return (1);
}
