/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:55:03 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/08 17:36:30 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
int	main(int argc, char **argv)
{
	int result;
	int ft_result;
	
	if (argc > 1)
	{
		result = strlen(argv[1]);
		ft_result = ft_strlen(argv[1]);
		printf("%i\n%i", result, ft_result);
	}
}*/
