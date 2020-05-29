/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:44:14 by lcandido          #+#    #+#             */
/*   Updated: 2020/05/28 22:36:15 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** O projeto consiste em permitir que o código abra e leia um arquivo de texto e execute a 
** leitura das linhas do arquivo através de um loop conforme o tamanho do buffer 
** definido através da flag BUFFER_SIZE em gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xx -g *.c
** O loop é terminado quando uma quebra de linha é encontrada e o valor de retorno é definido como
** 1, para linha lida, 0, para EOF ou -1, quando um erro acontece.
** Este projeto utiliza os conceitos de variável estática, treino com a biblioteca de IO e uso
** responsável de alocação de memória
*/

int		get_next_line(int fd, char **line)
{
	static char		*s_line;
	char			*l_buffer;
	register int	result;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	result = 1;
	*line = NULL;
	l_buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!s_line)
		s_line = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (newline(s_line) == -1 && result >= 1 && result <= BUFFER_SIZE)
	{
		result = read(fd, l_buffer, BUFFER_SIZE);
		if (result >= 1 && result <= BUFFER_SIZE && s_line)
			s_line = ft_strjoin(s_line, l_buffer);
		ft_bzero(l_buffer);
	}
	if (result >= 0 && result <= BUFFER_SIZE)
		s_line = cleanline(line, s_line, newline(s_line));
	free(l_buffer);
	if (result >= 1 && result <= BUFFER_SIZE)
		return (1);
	return (result == 0 ? 0 : -1);
}

/*
** Responsável por concatenar duas strings
*/

char	*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	register int	i;
	register int	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)ft_calloc(i + j + 1, sizeof(char));
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (str);
}

/* 
** A função recebe como parâmetro **line e *s_line, que contem uma string com uma quebra de linha
** em alguma posição. *cleanline é responsável por copiar os caracteres até o \n para a *line e
** retornar uma string com os caracteres seguintes para a próxima interação.
*/

char	*cleanline(char **line, char *s_line, int j)
{
	char	*l_temp;

	if (j >= 0)
	{
		s_line[j] = '\0';
		*line = (char*)ft_calloc(ft_strlen(s_line) + 1, sizeof(char));
		l_temp = (char*)ft_calloc(ft_strlen(&s_line[j + 1]) + 1, sizeof(char));
		ft_strlcpy(*line, s_line, ft_strlen(s_line) + 1);
		ft_strlcpy(l_temp, &s_line[j + 1], ft_strlen(&s_line[j + 1]) + 1);
		free(s_line);
		s_line = NULL;
		return (l_temp);
	}
	*line = (char*)ft_calloc(ft_strlen(s_line) + 1, sizeof(char));
	ft_strlcpy(*line, s_line, ft_strlen(s_line) + 1);
	free(s_line);
	s_line = NULL;
	return (s_line);
}

/* 
** Verifica se existe uma quebra de linha na string passada como parâmetro, retornando o índice
** caso o encontre. Retorna -1 em caso contrário.
*/

int		newline(char *s_line)
{
	int	i;

	i = 0;
	if (!s_line)
		return (-1);
	while (s_line[i])
	{
		if (s_line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}