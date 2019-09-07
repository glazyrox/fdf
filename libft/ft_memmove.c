/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:10:09 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/12/13 16:53:44 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*arr1;
	unsigned char	*arr2;
	size_t			i;

	arr1 = (unsigned char*)dst;
	arr2 = (unsigned char*)src;
	i = 0;
	if (!dst && !src)
		return (0);
	if (arr1 > arr2)
	{
		while (len)
		{
			arr1[len - 1] = arr2[len - 1];
			len--;
		}
	}
	while (len)
	{
		arr1[i] = arr2[i];
		len--;
		i++;
	}
	return (dst);
}
