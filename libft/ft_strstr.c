/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:01:39 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/11/29 13:47:32 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *heystack, const char *needle)
{
	int		i;
	int		g;
	char	*arr1;
	char	*arr2;
	int		len;

	len = ft_strlen(needle) - 1;
	arr1 = (char*)heystack;
	arr2 = (char*)needle;
	i = 0;
	g = 0;
	if (!arr2[0])
		return (arr1);
	while (arr1[i])
	{
		while (arr1[i + g] == arr2[g] && arr2[g])
			g++;
		if (arr2[g] == '\0')
			return (&arr1[i]);
		i++;
		g = 0;
	}
	return (NULL);
}
