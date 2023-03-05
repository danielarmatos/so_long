/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:59:09 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/18 20:10:32 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nsize(int x)
{
	int		size;

	size = 0;
	if (x < 0)
		size++;
	while (x)
	{
		x = x / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	a;
	int		size;

	if (n == 0)
		return (ft_strdup("0"));
	a = n;
	size = ft_nsize(n);
	result = (char *) malloc((size + 1) * sizeof(char));
	if (!result)
		return (0);
	result[size] = '\0';
	if (a < 0)
	{
		result[0] = '-';
		a = a * -1;
	}
	while (a > 0)
	{
		size = size - 1;
		result[size] = a % 10 + '0';
		a = a / 10;
	}
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	int		n;
	char	*result;

//	n = -123456789;
	n = 0;
	result = ft_itoa(n);
	puts(result);
}*/
