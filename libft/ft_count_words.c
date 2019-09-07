/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:24:29 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/12/16 14:33:03 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(const char *s, char c)
{
	int		count;
	char	*temp;
	int		i;

	i = 0;
	temp = (char*)s;
	count = 0;
	while (temp[i++] == c)
		;
	while (temp[i] != '\0')
	{
		while (temp[i] == c && temp[i] != '\0')
			i++;
		if (temp[i] == '\0')
			return (count);
		while (temp[i] != c && temp[i] != '\0')
			i++;
		count++;
	}
	return (count);
}
