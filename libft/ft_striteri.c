/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:00:40 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/24 15:51:33 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s)
		f(i++, s++);
}
/*
void	ft_test(unsigned int n, char *s)
{
	printf("string index is: %c\nn is: %i\n", s[n], n);
	s[n] = 'a';
}

int	main(void)
{
	char s[] = "Hello";

	ft_striteri(s, ft_test);
	puts(s);
}*/
