/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:42:11 by lgaudino          #+#    #+#             */
/*   Updated: 2023/03/02 15:44:41 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*result;
	char	*tmp_s1;

	tmp_s1 = s1;
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(s1_len + s2_len + 1);
	if (!result)
		return (NULL);
	while (*tmp_s1)
		result[i++] = *tmp_s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	free(s1);
	return (result);
}

static char	*ft_free_s(char *s, int free_s)
{
	if (free_s)
		free(s);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len, int free_s)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (!s[0])
		return (ft_free_s(s, free_s));
	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i + start < s_len && len--)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	ft_free_s(s, free_s);
	return (sub);
}
