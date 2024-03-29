/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:42:20 by lgaudino          #+#    #+#             */
/*   Updated: 2023/03/02 15:42:36 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *saved)
{
	char	*buff;
	int		read_len;

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
	static char	*saved[1024];
	size_t		str_end;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved[fd])
	{
		saved[fd] = malloc(sizeof(char));
		saved[fd][0] = '\0';
	}
	saved[fd] = ft_read_line(fd, saved[fd]);
	if (!saved[fd])
		return (NULL);
	str_end = 0;
	while (saved[fd][str_end] != '\n' && saved[fd][str_end])
		str_end++;
	line = ft_substr(saved[fd], 0, str_end + 1, 0);
	saved[fd] = ft_substr(saved[fd], str_end + 1, BUFFER_SIZE + 1, 1);
	return (line);
}
