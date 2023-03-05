/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:52:09 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/17 19:29:42 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size)
	{
		while (src[i] && (i < (size - 1)))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen((char *)src));
}
/*
int	main(void)
{
//	char dest[] = "Hello world";
//	const char src[]  = "ola ola";
	char dest1[] = "Hello world";
	const char src1[]  = "ola ola";
//	strlcpy(dest, src, 4);
	ft_strlcpy(dest1, src1, 4);
//	printf("%s\n", dest);
	printf("%s", dest1);
}*/
