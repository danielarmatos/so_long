/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:57:45 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/19 17:04:25 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*str;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen((char *)s1) + ((ft_strlen((char *)s2)) + 1);
	str = malloc(sizeof(char) * len);
	i = 0;
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "Hello ";
	char	s2[] = "world!";
	char	*result;

	result = ft_strjoin(s1, s2);
	puts(result);
}*/
