/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:44:55 by fcretin           #+#    #+#             */
/*   Updated: 2024/11/15 11:38:46 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_count_len(const char *src, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (i < size && src[i - 1] != '\n')
		i++;
	return (i);
}

ssize_t	ft_strlcpy_and_cut(char *dst, const char *src, char *dst2, ssize_t size)
{
	ssize_t		i;
	ssize_t		j;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	j = ft_count_len(src , size);
	dst = malloc(j + 1);
	if (!dst)
		return (NULL);
	if (j <= (size - 1))
		dst2 = malloc(j - size);
	while (i < size && src[i - 1] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while ((i + j) < size)
		j++;
	while (i < size)
		*dst2++ = src[i++];
	return (ft_strlen(dst));
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*str;
	char		*buff[BUFFER_SIZE];
	ssize_t		i;
	ssize_t		j;

	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		j = ft_strlcpy_and_cut(str, buff, stock, BUFFER_SIZE);
		if (!str)
		{
			if (!stock)
				return (NULL);
			else
				return (free(stock), NULL);
		}
	}
	return (str);
}


		str = // char strnew = strjoin(malloc)(size_of {&len_str(s1) + len_buff(s2)) to cat then} free str to return;