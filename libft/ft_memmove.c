/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:15:36 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/19 15:48:43 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest1;
	char	*src1;

	dest1 = (char *)dest;
	src1 = (char *)src;
	if (!dest1 && !src1)
		return (0);
	if (dest1 > src1)
	{
		while (n-- > 0)
			dest1[n] = src1[n];
	}
	else
	{
		while (n-- > 0)
			*dest1++ = *src1++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char dest[] = "dest string";
	const char src[]  = "source lala";
	char dest1[] = "dest string";
	const char src1[]  = "source lala";
	int x = 10;
	memmove(dest, src, x);
	printf("%s", dest);
	ft_memmove(dest1, src1, x);
	printf("\n%s", dest1);
}*/
