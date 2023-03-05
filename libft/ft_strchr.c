/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:04:13 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/19 13:50:20 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *) s + i);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	s[] = "bonjour";
	const char  s1[] = "bonjour";
	int	c = 'j';
	char *result;
	char *result1;

	result = strchr(s, c);
	result1 = ft_strchr(s1, c);
	printf("%s\n", result);
	printf("%s", result1);
}*/
