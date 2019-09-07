/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:34:58 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/12/09 15:11:49 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	if (size + 1 == 0)
		return (0);
	arr = malloc(sizeof(char) * (size + 1));
	if (arr == 0)
		return (NULL);
	while (size >= i)
	{
		arr[i] = '\0';
		i++;
	}
	return (arr);
}
