/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:45:49 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/06 18:01:53 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
int	main(void)
{
	int	result;
	int	ft_result;
	int	a;

	a = 'b';
	result = toupper(a);
	ft_result = ft_toupper(a);
	printf("%i\n%i", result, ft_result);
}*/
