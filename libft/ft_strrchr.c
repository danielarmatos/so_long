/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:57:05 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/19 14:00:58 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen((char *)s);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char *)&s[len]);
		len--;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char	s[50] = "Hello world";
	const char  s1[50] = "Hello world";
	int	c = 'o';
	char *result;
	char *result1;

	result = strrchr(s, c);
	result1 = ft_strrchr(s1, c);
	printf("%s\n", result);
	printf("%s", result1);
}*/
