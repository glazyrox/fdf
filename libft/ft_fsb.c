/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:07:33 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/07/03 15:49:24 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fsb(char *s, unsigned int star, size_t len, int flag)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	while (i < len && s[star + i] != '\0')
	{
		str[i] = s[star + i];
		i++;
	}
	str[i] = '\0';
	flag == 1 ? ft_strdel(&s) : 0;
	return (str);
}
