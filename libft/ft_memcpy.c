/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:01:17 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/19 15:26:42 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest1;
	const unsigned char	*src1;

	if (!dest && !src)
		return (0);
	i = 0;
	dest1 = dest;
	src1 = src;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}	
	return (dest);
}
/*
Instead of using:
	dest1[i] = src1[i];
We could use instead:
	*((char *)dest + i) = *((char *)src + i);

int main () 
{
	const char src[] = "Hello world!";
	char src2[] = "Hello world!";
	char dest[] = "Ola ola";
	char dest2[] = "Ola ola";
	int	x = 50;
	
	memcpy(dest, src, x);
	puts(dest);
	ft_memcpy(dest2, src2, x);
	puts(dest2);

	return(0);
}*/
