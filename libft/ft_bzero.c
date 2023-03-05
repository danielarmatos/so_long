/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:43:30 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/08 11:21:16 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
int	main(void)
{
	char	str[] = "Hello World!";
	char	str2[] = "Hello World!";

	bzero(str, 4);
	puts(str);
	ft_bzero(str2, 4);
	puts(str2);
	return (0);
}*/
