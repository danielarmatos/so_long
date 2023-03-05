/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:18:31 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/19 13:37:51 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen((char *)src);
	if (! dest)
		dest_len = 0;
	else
		dest_len = ft_strlen(dest);
	if (dest_len >= size)
		return (src_len + size);
	i = 0;
	while (src[i] && i < (size - dest_len - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}
/*
#include <stdio.h>

int	main(void)
{
	char		dst[] = "This is ";
	const char	src[] = "a potentially long string";
	int	result;

	result = ft_strlcat(dst, src, 5);
	printf("%s\n%i", dst, result);
}*/
