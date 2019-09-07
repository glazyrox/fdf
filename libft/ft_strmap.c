/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:15:52 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/12/09 15:11:05 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*nstr;
	size_t	i;
	size_t	len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	nstr = malloc(sizeof(char) * (len + 1));
	if (nstr == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		nstr[i] = (f)(s[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
