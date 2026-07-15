/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:56:23 by gscorzon          #+#    #+#             */
/*   Updated: 2026/07/11 16:34:34 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

//# ifndef GNL_DONE

//#  define GNL_DONE (char *)1

//#endif // GNL_DONE

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE  10000000

# endif // BUFFER_SIZE

# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2, size_t i);
int		ft_strchr_gnl(const char *s, int c);
char    *ft_arrfill(char *buf, size_t i);

#endif // GET_NEXT_LINE_H
