/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:02:19 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/12/01 17:08:35 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	*s;
	int		count;

	s = ft_utoa(n);
	count = ft_putstr(s);
	free(s);
	return (count);
}

int	ft_putnbr(int n)
{
	char	*s;
	int		count;

	s = ft_itoa(n);
	count = ft_putstr(s);
	free(s);
	return (count);
}
