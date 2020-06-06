/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 14:38:53 by flexer            #+#    #+#             */
/*   Updated: 2020/06/06 14:40:11 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt",O_RDONLY);
	while(get_next_line(fd, &line))
		printf("%s\n", line);
	free(line);
}

