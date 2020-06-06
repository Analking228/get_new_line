/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:00:32 by flexer            #+#    #+#             */
/*   Updated: 2020/06/06 14:42:55 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s);
char				*ft_strlcpy(char *dest, const char *src, size_t n);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char const *prestr, char const *sufstr);
char				*ft_strchr(const char *s, int c);

#endif
