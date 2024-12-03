/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:38:20 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/03 10:54:46 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *p, size_t c)
{
	size_t			i;

	i = 0;
	while (i < c)
		((char *)p)[i++] = 0;
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str && str[i] != (char)c && str[i])
		i++;
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s && d < s + size)
	{
		while (size-- > 0)
			d[size] = s[size];
	}
	else
	{
		while (i < size)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] && s2[i - 1] != '\n')
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}
