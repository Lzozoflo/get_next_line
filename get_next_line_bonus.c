/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:49:31 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/03 12:09:44 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_mmv(char *buff, char *line)
{
	char	*newline;

	newline = ft_strchr(buff, '\n');
	if (newline)
		ft_memmove(buff, newline + 1, ft_strlen(newline + 1) + 1);
	return (line);
}

char	*ft_reader(int fd, char *buff, char *line)
{
	int		r_read;

	while (1)
	{
		if (buff[0] == '\0')
		{
			r_read = read(fd, buff, BUFFER_SIZE);
			if (r_read < 0)
			{
				if (line)
					free(line);
				return (NULL);
			}
			if (r_read == 0)
				return (line);
			buff[r_read] = '\0';
		}
		line = ft_strjoin(line, buff);
		if (!line)
			return (NULL);
		if (ft_strchr(buff, '\n'))
			return (ft_mmv(buff, line));
		ft_bzero(buff, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	static char	buff[MAX_FD][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || MAX_FD <= 0)
		return (NULL);
	line = NULL;
	line = ft_reader(fd, buff[fd], line);
	if (!line)
		return (NULL);
	return (line);
}
