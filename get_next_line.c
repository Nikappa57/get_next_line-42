/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:44:53 by lgaudino          #+#    #+#             */
/*   Updated: 2023/03/02 15:44:58 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *saved)
{
	char		*buff;
	int			read_len;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_len = 1;
	while (!ft_strchr(saved, '\n') && read_len)
	{
		read_len = read(fd, buff, BUFFER_SIZE);
		if (read_len == -1)
		{
			free(buff);
			free(saved);
			return (NULL);
		}
		buff[read_len] = '\0';
		saved = ft_strjoin(saved, buff);
	}
	free(buff);
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	size_t		str_end;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved)
	{
		saved = malloc(sizeof(char));
		*saved = '\0';
	}
	saved = ft_read_line(fd, saved);
	if (!saved)
		return (NULL);
	str_end = 0;
	while (saved[str_end] != '\n' && saved[str_end])
		str_end++;
	line = ft_substr(saved, 0, str_end + 1, 0);
	saved = ft_substr(saved, str_end + 1, BUFFER_SIZE + 1, 1);
	return (line);
}
