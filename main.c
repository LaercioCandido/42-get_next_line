/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 19:27:11 by lcandido          #+#    #+#             */
/*   Updated: 2020/05/29 19:29:44 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main()
{
	int			fd;
	int			ret;
	char		*line;

	fd = open("./test1.txt", O_RDONLY);
	ret = get_next_line(fd, &line);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		if (ret <= 0)
			break;
		ret = get_next_line(fd, &line);
	}
	switch (ret)
	{
		case -1:
		printf("Arquivo terminou com erro");
		break;
		case 0:
		printf("PROGRAMA TERMINOU DE MANEIRA CORRETA.");
		break;
		case 1:
		printf("Arquivo não foi lido por completo.");
		break;
	}
	close(fd);
	return (ret);
}
