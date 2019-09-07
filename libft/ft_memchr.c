/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:34:26 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/11/29 13:19:59 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*arr;
	unsigned char		sy;

	arr = (unsigned char*)s;
	i = 0;
	sy = (unsigned char)c;
	while (i < n)
	{
		if (arr[i] == sy)
			return (arr + i);
		i++;
	}
	return (NULL);
}
