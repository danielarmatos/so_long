/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:54:20 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/24 16:59:21 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}

static int	ft_word_size(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static char	*ft_word(char **arr, char *s, int i, char c)
{
	char	*word;
	int		wsize;

	wsize = ft_word_size(s, c, i);
	word = ft_substr(s, i, wsize);
	if (!arr)
	{
		while (*arr--)
			free(*arr--);
		free(arr);
		return (NULL);
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		i;
	int		j;
	char	**arr;

	if (!s)
		return (0);
	words = ft_words(s, c);
	arr = (char **) malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	j = -1;
	while (++j < words)
	{
		while (s[i] == c)
			i++;
		arr[j] = ft_word(arr + j, (char *)s, i, c);
		i += ft_word_size(s, c, i);
	}
	arr[j] = 0;
	return (arr);
}
/*
#include <stdio.h>

int	main(void)
{
//	char	s[] = "    Hello    wor  l d!  ";
	char	s[] = "      split       this for   me  !       ";
	char	**result;
	int		i = 0;
	
	result = ft_split(s, ' ');
	while (result[i])
	{
		puts(result[i]);
		i++;
	}
}*/
