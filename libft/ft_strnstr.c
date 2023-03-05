/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:49:50 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/19 15:59:54 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	char		*pbig;
	char		*plittle;

	if (!big && !len)
		return (0);
	pbig = (char *) big;
	plittle = (char *) little;
	i = 0;
	j = 0;
	if (!plittle[j])
		return (pbig);
	while (pbig[i] && i < len)
	{
		while (pbig[i + j] && pbig[i + j] == plittle[j] && (i + j) < len)
			j++;
		if (!plittle[j])
			return (pbig + i);
		i++;
		j = 0;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Foo Bar Baz";
	char	str2[] = "Bar";
	char	*result;

	result = ft_strnstr(str1, str2, 0);
	puts(result);
}*/
