/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:49:43 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/12/13 19:07:37 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*nstr;
	size_t	len;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	nstr = (char*)malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (NULL);
	while (s[i])
	{
		nstr[i] = (*f)(i, s[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
