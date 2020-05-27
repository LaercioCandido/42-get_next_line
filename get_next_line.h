/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:44:23 by lcandido          #+#    #+#             */
/*   Updated: 2020/05/26 13:49:27 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
int	check_line(char *str);
char	*cleanline(char **line, char *s_line);
int	newline(char *s_line);
size_t	ft_strlen(char *str);
void	ft_bzero(char *str);
char	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char *str, int start, size_t len);

#endif
