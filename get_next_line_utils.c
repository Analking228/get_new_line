/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:00:50 by flexer            #+#    #+#             */
/*   Updated: 2020/06/07 16:28:25 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(const char *s)
{
	size_t			len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char				*ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t			i;
	char			*psrc;

	i = 0;
	psrc = (char*)src;
	while (n--)
	{
		dest[i] = psrc[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char				*ft_strdup(const char *str)
{
	char			*newstr;
	size_t			len;

	len = ft_strlen(str);
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, str, len);
	newstr[len + 1] = '\0';
	return (newstr);
}

char		*ft_strjoin(char const *prestr, char const *sufstr)
{
	size_t		newl;
	size_t		i;
	size_t		j;
	char		*newptr;

	if (!prestr || !sufstr)
		return (NULL);
	i = 0;
	j = 0;
	newl = ft_strlen(prestr) + ft_strlen(sufstr) + 1;
	newptr = (char *)malloc(newl * sizeof(char));
	if (!newptr)
		return (NULL);
	while (prestr[i])
		newptr[j++] = prestr[i++];
	i = 0;
	while (sufstr[i])
		newptr[j++] = sufstr[i++];
	newptr[j] = 0;
	return (newptr);
}

char		*ft_strchr(const char *s, int c)
{
	char		*ptrs;

	ptrs = (char *)s;
	while ((*ptrs != '\0') && (*ptrs != c))
		ptrs += 1;
	if (*ptrs == c)
		return (ptrs);
	return (NULL);
}