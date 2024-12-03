/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:38:23 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/02 16:41:54 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <fcntl.h>  // Pour open()
# include <stdio.h>//dell
# include <unistd.h>
# include <stdlib.h> // Pour malloc(), free()

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *p, size_t c);
char	*ft_strchr(const char *str, int c);
void	*ft_memmove(void *dest, const void *src, size_t size);
char	*ft_strjoin(char *s1, const char *s2);

#endif