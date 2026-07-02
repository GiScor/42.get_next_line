/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:56:23 by gscorzon          #+#    #+#             */
/*   Updated: 2026/07/02 15:15:14 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif // BUFFER_SIZE
#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*linefill(char *buf, int len);
char	*gnl(int fd, char *buf, char *line, int found);

#endif // GET_NEXT_LINE_H

