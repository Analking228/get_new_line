/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:00:19 by flexer            #+#    #+#             */
/*   Updated: 2020/06/07 16:57:35 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"

static void		dup_with_free(char *dup, char **line)
{
	char		*tmp;

	tmp = NULL;
	if (*line)
		tmp = *line;
	*line = ft_strdup(dup);
	if (tmp)
		free(tmp);
}

static void		join_with_free(char **line, char *buf)
{
	char		*tmp;

	tmp = NULL;
	if (*line)
		tmp = *line;
	*line = ft_strjoin(*line, buf);
	if (tmp)
		free(tmp);
}

static char		*is_kept(char *keeper, char **line)
{
	char		*ptr;
	char		*tmp;

	ptr = NULL;
	if (*keeper)
	{
		ptr = ft_strchr(keeper, '\n');
		if (ptr)
		{
			*ptr = 0;
			dup_with_free(keeper, line);
			ptr++;
			ft_strlcpy(keeper, ptr, ft_strlen(ptr));
		}
		else
		{
			dup_with_free(keeper, line);
		}
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
			dup_with_free(++ptrn, &keeper);
		}
		join_with_free(line, buf);
	}
	if (ft_strlen(keeper) || ft_strlen(*line) || control)
		return (1);
	return (0);
}
