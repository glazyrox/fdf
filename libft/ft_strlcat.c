/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:43:14 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/11/27 20:32:31 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len1;
	size_t len2;
	size_t res;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if ((int)(size - 1 - len1) < 0)
		res = 0;
	else
		res = (size - 1) - len1;
	ft_strncat(dst, src, res);
	if (len1 + len2 > len2 + size)
		return (len2 + size);
	else
		return (len1 + len2);
}
