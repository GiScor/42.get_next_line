/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:56:23 by gscorzon          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/22 19:12:43 by gscorzon         ###   ########.fr       */
=======
/*   Updated: 2026/07/23 16:49:35 by gscorzon         ###   ########.fr       */
>>>>>>> experimental
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

//# ifndef GNL_DONE

//#  define GNL_DONE (char *)1

//#endif // GNL_DONE

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE  42

# endif // BUFFER_SIZE

# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*ft_arrfill(char *src, size_t i);
char	*ft_strjoin(char *s1, char *s2, size_t i);
char	*get_next_line(int fd);
char	*linefill(char **stash);
int		ft_strchr_gnl(const char *s, int c);
int		readnstash(int fd, char **buf, char **stash);
void	arr_init(char **arr, size_t n);
void	linefillhelper(char **stash, char **line, int len, int nl);
void	movearr(char **arr, int n);

#endif // GET_NEXT_LINE_H
