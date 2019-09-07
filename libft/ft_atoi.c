/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:55:24 by rgwayne-          #+#    #+#             */
/*   Updated: 2018/12/15 22:40:08 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	long long int	nbr;
	int				ifneg;
	long long int	proof;

	i = 0;
	nbr = 0;
	ifneg = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		ifneg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		proof = nbr;
		nbr = 10 * nbr + (str[i++] - '0');
		if ((nbr > 0 && proof < 0) || (nbr < 0 && proof > 0))
			return (ifneg == 1 ? 0 : -1);
	}
	if (ifneg == 1)
		return (-nbr);
	return (nbr);
}
