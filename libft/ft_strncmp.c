/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:19:38 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/12/12 20:08:49 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*arr1;
	unsigned char	*arr2;

	i = 0;
	arr1 = (unsigned char*)s1;
	arr2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	if (arr1[i] == '\0' && arr2[i] == '\0' && arr1[i] == arr2[i])
	{
		if (arr1[i] == '\0')
			return (0);
		else
			return (1);
	}
	while (arr1[i] != '\0' && arr2[i] != '\0' && arr1[i] == arr2[i] && i < n)
	{
		if (arr1[i] != arr2[i])
			return (arr1[i] - arr2[i]);
		i++;
	}
	if (arr1[i] != arr2[i] && i != n)
		return (arr1[i] - arr2[i]);
	return (0);
}
