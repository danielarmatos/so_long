/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:58:12 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/24 15:58:18 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		size;
	int		i;
	char	*result;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	size = end - start;
	result = (char *) malloc((size + 2) * sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (i <= size)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	return (ft_trim(s1, set));
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
//	char	s1[] = "* * * He*llo w* orld!* * * ";
//	char	set[] = "* ";
	char	s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
	char	set[] = " ";
	char	*result;

	result = ft_strtrim(s1, set);
	puts(result);
	free(result);
}*/
