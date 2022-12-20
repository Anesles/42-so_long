/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:54:26 by brumarti          #+#    #+#             */
/*   Updated: 2022/12/20 17:26:48 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*read_buffer(int fd)
{
	char	*aux;
	int		bytes;

	aux = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!aux)
		return (NULL);
	bytes = read(fd, aux, BUFFER_SIZE);
	if (bytes < 0)
	{
		free(aux);
		return (NULL);
	}
	aux[bytes] = 0;
	return (aux);
}

char	*expand_buf(char *buf, int fd)
{	
	size_t	new_len;
	char	*new_buf;
	char	*aux;	

	aux = read_buffer(fd);
	if (!aux)
		return (NULL);
	if (!aux[0])
	{
		free(aux);
		return (buf);
	}
	if (!buf)
		return (aux);
	new_len = ft_strlen(aux) + ft_strlen(buf);
	new_buf = malloc(new_len + 1);
	if (!new_buf)
		return (NULL);
	ft_strlcpy(new_buf, buf, new_len + 1);
	ft_strlcat(new_buf, aux, new_len + 1);
	free(buf);
	free(aux);
	return (new_buf);
}

char	*new_line(char *buf, char *line)
{
	char	*new_buf;
	int		index;
	size_t	new_len;

	if (!buf || !line)
		return (buf);
	if (ft_strlen(buf) == ft_strlen(line))
	{
		free(buf);
		return (NULL);
	}
	index = 0;
	index += ft_strlen(line);
	new_len = ft_strlen(buf) - ft_strlen(line);
	new_buf = ft_substr(buf, index, new_len + 1);
	if (!new_buf)
		return (NULL);
	free(buf);
	return (new_buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[4096];
	char		*line;
	size_t		old_len;	

	if (fd < 0 || fd > 4095 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	if ((int)ft_strchr(buf[fd], '\n') == -1)
	{
		old_len = ft_strlen(buf[fd]);
		buf[fd] = expand_buf(buf[fd], fd);
		if (old_len == ft_strlen(buf[fd]))
			line = ft_substr(buf[fd], 0, ft_strlen(buf[fd]));
	}
	if (!buf[fd])
		return (NULL);
	if (!line && (int)ft_strchr(buf[fd], '\n') != -1)
		line = ft_substr(buf[fd], 0, ft_strchr(buf[fd], '\n') + 1);
	if (line)
	{
		buf[fd] = new_line(buf[fd], line);
		return (line);
	}
	return (get_next_line(fd));
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("gnlTester/files/multiple_line_with_nl", O_RDWR);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (ft_strchr(line, '\n'))
			printf("\n");
		free(line);
		if (!line)
			return (0);
	}
	close(fd);
}
