/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:51:06 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/08 17:47:10 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
		{
			if (str1[i] < str2[i])
				return (-1);
			else if (str1[i] > str2[i])
				return (1);
		}
	}
	return (0);
}
/*
int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s1 + i) ==
				*((unsigned char *)s2 + i))
			i++;
		else
			return ((*((unsigned char *)s1 + i)) -
						*((unsigned char *)s2 + i));
	}
	return (0);
}
*/
/*
int	main(void)
{
	char str1[] = "ABCdef";
	char str2[] = "ABCDEF";
	int	result;
	int	a = 2;

	result = memcmp(str1, str2, a);
	printf("%i\n", result);
	result = ft_memcmp(str1, str2, a);
	printf("%i\n", result);
}*/
