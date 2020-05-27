/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:43:52 by lcandido          #+#    #+#             */
/*   Updated: 2020/05/26 13:49:24 by lcandido         ###   ########.fr       */
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
** Responsável por extrair uma substring da string passada como parâmetro
*/

char	*ft_substr(char *str, int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (str == 0)
		return (0);
	s_len = ft_strlen(str);
	i = 0;
	if (!(substr = ft_calloc(len + 1, sizeof(char))))
		return (0);
	while (i < len && (start + i) < s_len)
	{
		substr[i] = str[start + i];
		i++;
	}
	//substr[i] = '\0';
	return (substr);
}