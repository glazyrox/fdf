/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:53:03 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/06/27 15:58:35 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fstrjoin(char *s1, char *s2, int flag)
{
	char	*str;
	size_t	i;
	size_t	g;

	if (!s1 || !s2)
		return (0);
	i = -1;
	g = -1;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == 0)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++g])
		str[i++] = s2[g];
	str[i] = '\0';
	ft_strdel(flag == 1 ? &s1 : &s2);
	if (flag == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (str);
}
