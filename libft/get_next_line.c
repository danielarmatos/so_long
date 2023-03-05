/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:44:53 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/12/10 18:12:05 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*save_last_buff(char *str)
{
	int		i;
	int		k;
	char	*result;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	result = (char *) malloc ((ft_strlen(str) - i + 1) * sizeof(char));
	if (!result)
		return (0);
	k = 0;
	while (k < (ft_strlen(str) - i))
	{
		result[k] = str[i + 1 + k];
		k++;
	}
	result[k] = '\0';
	free(str);
	return (result);
}

static char	*save_str(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	result = (char *) malloc ((i + 2) * sizeof(char));
	if (!result)
		return (0);
	while (j < i)
	{
		result[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
	{
		result[j] = str[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

static int	check_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*read_line(int fd, char *result)
{
	char	*buff;
	int		bytes_read;
	int		check;

	buff = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	check = 0;
	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && check == 0 && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(result);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		check = check_newline(buff);
		result = ft_strjoin02(result, buff);
	}
	free(buff);
	return (result);
}

char	*get_next_line(int fd)
{
	char			*result;
	static char		*last_buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	last_buff = read_line(fd, last_buff);
	if (!last_buff)
		return (NULL);
	result = save_str(last_buff);
	last_buff = save_last_buff(last_buff);
	return (result);
}
