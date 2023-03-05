/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:22:56 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/06 15:10:22 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
int	main(int argc, char **argv)
{
	int result;
	int ft_result;
	
	if (argc > 1)
	{
		result = isdigit(argv[1][0]);
		ft_result = ft_isdigit(argv[1][0]);
		printf("%i\n%i", result, ft_result);
	}
}*/
