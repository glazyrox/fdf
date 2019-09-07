/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:54:58 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/11/29 13:34:00 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*arr1;
	unsigned char	*arr2;

	arr1 = (unsigned char*)s1;
	arr2 = (unsigned char*)s2;
	i = 0;
	if (arr1[i] == '\0' ^ arr2[i] == '\0')
	{
		if (arr1[i] == '\0')
			return (-1);
		else
			return (1);
	}
	while (arr1[i] != '\0' && arr2[i] != '\0' && arr1[i] == arr2[i])
	{
		i++;
	}
	return (arr1[i] - arr2[i]);
}
