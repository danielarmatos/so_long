/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:18:39 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/19 16:03:17 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	result = (void *) malloc(nmemb * size);
	if (!result)
		return (0);
	ft_bzero(result, size * nmemb);
	return (result);
}
/*
int main(void) 
{
	int	i = 0;
	int	n = 3;
	int *result;
	int	*result1;
	
	result = (int*)calloc(n, sizeof(int));
	while (i < n)
	{
		printf("%d ", result[i]);
		i++;
	}
	free(result);
	printf("\n===\n");	
	i = 0;	
	result1 = (int*)ft_calloc(n, sizeof(int));
	while (i < n)
	{
		printf("%d ", result1[i]);
		i++;
	}
	free(result1);
}*/
