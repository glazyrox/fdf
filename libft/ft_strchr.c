/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:59:24 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/11/29 13:22:43 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char symb;
	char *arr;

	symb = (char)c;
	arr = (char*)ft_memchr(s, symb, ft_strlen(s));
	if (symb == 0)
		return ((char *)(s + ft_strlen(s)));
	else
		return (arr);
}
