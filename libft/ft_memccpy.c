/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:58:32 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/11/29 13:18:51 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*arr1;
	unsigned char	*arr2;
	unsigned char	smbl;

	arr1 = (unsigned char*)dst;
	arr2 = (unsigned char*)src;
	i = 0;
	smbl = (unsigned char)c;
	while (i < n)
	{
		arr1[i] = arr2[i];
		if (arr1[i] == smbl)
			return (arr1 + i + 1);
		i++;
	}
	return (0);
}
