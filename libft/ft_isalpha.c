/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:07:40 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/06 15:57:30 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/*
int	main(int argc, char **argv)
{
	int	result;
	int	ft_result;

	if (argc > 1)
	{
		result = isalpha(argv[1][0]);
		ft_result = ft_isalpha(argv[1][0]);
		printf("%i\n%i", result, ft_result);
	}
}*/
