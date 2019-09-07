/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:12:02 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/12/15 23:16:41 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long f)
{
	int		i;

	i = 0;
	if (f == 0)
	{
		i = 1;
		return (i);
	}
	if (f < 0)
	{
		i++;
		f = f * (-1);
	}
	while (f)
	{
		f = f / 10;
		i++;
	}
	return (i);
}

static char	*ft_final(long f)
{
	int		len;
	int		flg;
	char	*tmp;

	len = ft_len(f);
	flg = 0;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	tmp[len] = '\0';
	len = len - 1;
	if (f < 0)
	{
		flg = 1;
		f = f * -1;
	}
	while (len >= 0)
	{
		tmp[len] = f % 10 + 48;
		len--;
		f = f / 10;
	}
	if (flg == 1)
		tmp[0] = '-';
	return (tmp);
}

char		*ft_itoa(int n)
{
	char	*res;
	long	nbr;

	nbr = n;
	res = ft_final(nbr);
	return (res);
}
