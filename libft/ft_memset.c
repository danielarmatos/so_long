/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:01:10 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/08 17:37:13 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
/*
int main () 
{
	char str[50] = "Hello World!";
	char str2[50] = "Hello World!";
	
	memset(str, '$', 4);
	puts(str);
	ft_memset(str2, '$', 4);
	puts(str2);

	return(0);
}*/
