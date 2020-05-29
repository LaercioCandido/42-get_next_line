/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:44:23 by lcandido          #+#    #+#             */
/*   Updated: 2020/05/28 22:59:02 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
int		newline(char *s_line);
char	*ft_strjoin(char *s1, char *s2);
char	*cleanline(char **line, char *s_line, int index_newline);
size_t	ft_strlen(char *str);
void	ft_bzero(char *str);
char	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif
