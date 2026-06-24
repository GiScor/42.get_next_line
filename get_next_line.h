/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:56:23 by gscorzon          #+#    #+#             */
/*   Updated: 2026/06/24 13:55:05 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif // BUFFER_SIZE
#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*lalloc(char *buf);
size_t	ft_strlen(char *str);
char	*gnl_rec(int fd, char *buf, char *str);
int		ft_strchr(const char *s, int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strmerge(char *s1, char *s2);

#endif // GET_NEXT_LINE_H

