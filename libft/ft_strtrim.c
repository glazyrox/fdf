/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 00:55:14 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/11/30 06:01:29 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		strt;
	size_t		end;
	char		*str;

	str = NULL;
	strt = 0;
	if (!s)
		return (0);
	while (s[strt] == ' ' || s[strt] == '\t' || s[strt] == '\n')
		strt++;
	if (s[strt] == '\0')
	{
		str = malloc(sizeof(*str) * 1);
		*str = '\0';
		return (str);
	}
	end = ft_strlen(s) - 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && (int)end >= 0)
		end--;
	return (ft_strsub(s, (unsigned int)strt, end - strt + 1));
}
