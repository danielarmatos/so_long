/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:26:38 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/27 16:59:49 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_number(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static void	display_number(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
		write(1, &base[n], 1);
	if (n >= 16)
	{
		display_number(n / 16);
		display_number(n % 16);
	}
}

int	ft_putpointer(unsigned long n)
{
	if (!n)
		return (ft_putstr("(nil)"));
	write(1, "0x", 2);
	display_number(n);
	return (count_number(n) + 2);
}
