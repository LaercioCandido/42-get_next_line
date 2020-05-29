/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:43:52 by lcandido          #+#    #+#             */
/*   Updated: 2020/05/28 22:39:08 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Responsável por zerar os caracteres da string
*/

void	ft_bzero(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (i < BUFFER_SIZE && i < 1000000)
		{
			str[i] = '\0';
			i++;
		}
	}
}

/*
** Responsável por contar os caracteres da string
*/

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

/*
** Responsável por alocar espaço de memória e zerar os caracteres
*/

char	*ft_calloc(size_t count, size_t size)
{
	char		*str;
	size_t		i;

	if (count > 1000000)
		count = 1000000;
	str = (char *)malloc(count * size);
	i = 0;
	if (str)
	{
		while (i < count)
		{
			str[i] = '\0';
			i++;
		}
	}
	return (str);
}

/*
** Responsável por copiar uma substring da string passada como parâmetro
*/

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	if (src == 0)
		return (0);
	if (dstsize > 0)
	{
		i = 0;
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}