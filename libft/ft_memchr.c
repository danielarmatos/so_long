/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:55:34 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/18 18:21:44 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *) str;
	while (i < n)
	{
		if (*s == (unsigned char) c)
			return ((void *)s);
		s++;
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char str1[] = "Hello world";
	char str2[] = "Hello world";
	int	a = 'o';
	int b = 2;
	char *result;
	char *result1;

	result = memchr(str1, a, b);
	result1 = ft_memchr(str2, a, b);
	printf("String: %s\n", result);
	printf("String: %s\n", result1);
}*/
