/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:15:01 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/27 17:01:49 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_number(unsigned int n)
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

static void	display_number(unsigned int n, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	if (n < i)
		write(1, &base[n], 1);
	if (n >= i)
	{
		display_number((n / i), base);
		display_number((n % i), base);
	}
}

int	ft_putnbr_base(unsigned int n, char *base)
{
	display_number(n, base);
	return (count_number(n));
}
