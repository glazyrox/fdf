/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:32:26 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/01 17:23:56 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				find(char *gnl)
{
	int			i;

	i = 0;
	while (gnl[i])
	{
		if (gnl[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int				ft_endit(char *ends)
{
	int			g;

	g = 0;
	while (ends[g])
	{
		if (ends[g] == '\0')
			return (g);
		g++;
	}
	return (g);
}

int				cycle(char **src, char **line)
{
	if (find(*src) >= 0)
	{
		*line = ft_strsub(*src, 0, find(*src));
		*src = ft_fsb(*src, find(*src) + 1, ft_strlen(*src), 1);
		return (1);
	}
	if (ft_endit(*src))
	{
		*line = ft_strsub(*src, 0, ft_endit(*src));
		ft_strdel(src);
		return (1);
	}
	else if (src[0] == '\0')
		return (0);
	return (0);
}

int				ft_return(int cnt, char *src)
{
	if (cnt == 0 && !src)
	{
		free(src);
		return (0);
	}
	if (cnt == -1)
		return (-1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		arr[BUFF_SIZE + 1];
	static char	*src[SIZE];
	int			cnt;

	if (fd < 0 || !line || (fd > SIZE))
		return (-1);
	ft_bzero(arr, BUFF_SIZE + 1);
	while ((cnt = read(fd, arr, BUFF_SIZE)) > 0)
	{
		if (src[fd])
			src[fd] = ft_fstrjoin(src[fd], arr, 1);
		else
			src[fd] = ft_strdup(arr);
		if (find(src[fd]) >= 0)
		{
			*line = ft_strsub(src[fd], 0, find(src[fd]));
			src[fd] = ft_fsb(src[fd], find(src[fd]) + 1, ft_strlen(src[fd]), 1);
			return (1);
		}
		ft_bzero(arr, BUFF_SIZE + 1);
	}
	while ((cnt = read(fd, arr, BUFF_SIZE)) == 0 && src[fd])
		return (cycle(&src[fd], line));
	return (ft_return(cnt, src[fd]));
}
