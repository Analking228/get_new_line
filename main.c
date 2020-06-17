/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 20:12:02 by flexer            #+#    #+#             */
/*   Updated: 2020/06/17 13:46:40 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
//#include "get_next_line_bonus.c"
//#include "get_next_line_utils_bonus.c"
//#include "get_next_line_bonus.h"
int main()
{
    int     fd;
    char    *line;
    int     get;
    printf("BUF SIZE = %d\n", BUFFER_SIZE);
    fd = open("test", O_RDONLY);
    while ((get = get_next_line(fd, &line)) > 0)
    {
        printf("|%s\n", line);
        free(line);
    }
    if (get < 0)
        printf("Error while reading file\n");
    else if (get == 0)
    {
        printf("|%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
