/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:00:19 by flexer            #+#    #+#             */
/*   Updated: 2020/06/06 14:40:08 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"

static char		*is_kept(char *keeper, char **line)
{
	char		*ptr;

	ptr = NULL;
	if (*keeper)
		if (ptr = ft_strchr(keeper, '\n'))
		{
			*ptr = 0;
			*line = ft_strdup(keeper);
			ft_strlcpy(keeper, ++ptr, ft_strlen(ptr));
		}
		else
		{
			*line = ft_strdup(keeper);
		}
	else
		*line = ft_strdup("");
	return (ptr);
	
}

int				get_next_line(int fd, char **line)
{
	static int	control;
	static char	buf[BUFFER_SIZE + 1];
	char		*ptrn;
	static char	*keeper;

	if(!control)
	{
		keeper = (char*)malloc(sizeof(char));
		*keeper = 0;
	}
	ptrn = is_kept(keeper, line);
	while (!ptrn && (control = read(fd, buf, BUFFER_SIZE)))
	{
		buf[control] = 0;
		if ((ptrn = ft_strchr(buf, '\n')))
		{
			*ptrn = 0;
			keeper = ft_strdup(++ptrn);
		}
		*line = ft_strjoin(*line, buf);
	}
	if (ft_strlen(keeper) || ft_strlen(*line) || control)
		return (1);
	return (0);
}
