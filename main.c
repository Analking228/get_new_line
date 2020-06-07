/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 14:38:53 by flexer            #+#    #+#             */
/*   Updated: 2020/06/07 16:18:54 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("test",O_RDONLY);
	while(get_next_line(fd, &line))
	{
		printf("%s\n", line);
		i++;
	}
	printf("Number of lines -- %d\n", i);
	free(line);
}

