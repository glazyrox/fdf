/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:58:44 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/11/29 15:19:49 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *arr;

	if (size > 0)
	{
		arr = (void *)malloc(sizeof(unsigned char) * size);
		if (arr == 0)
			return (NULL);
		else
		{
			ft_bzero(arr, size);
			return (arr);
		}
	}
	else
		return (NULL);
}
