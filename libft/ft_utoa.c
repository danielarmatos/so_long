/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:59:09 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/12/01 17:07:22 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nsize(unsigned int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_utoa(unsigned int nbr)
{
	char			*result;
	int				size;
	unsigned int	n;

	size = ft_nsize(nbr);
	n = nbr;
	result = (char *) malloc((size + 1) * sizeof(char));
	if (!result)
		return (0);
	result[size] = '\0';
	if (n == 0)
		result[0] = '0';
	while (n)
	{
		size = size - 1;
		result[size] = n % 10 + '0';
		n = n / 10;
	}
	return (result);
}
