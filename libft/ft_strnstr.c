/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:35:11 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/12/12 18:30:37 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *heystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	g;
	char	*arr1;
	char	*arr2;

	arr1 = (char*)heystack;
	arr2 = (char*)needle;
	i = 0;
	if (!arr2[0])
		return (arr1);
	while (arr1[i])
	{
		g = 0;
		while (arr1[i + g] == arr2[g] && len > i + g)
		{
			g++;
			if (arr2[g] == '\0')
			{
				return (&arr1[i]);
			}
		}
		i++;
	}
	return (NULL);
}
