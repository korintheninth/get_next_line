#include "get_next_line_bonus.h"

char	*get_rough(char *remainder, int fd)
{
	char	*buffer;
	int		size;

	size = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr(remainder, '\n') && size)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			free(remainder);
			return (0);
		}
		buffer[size] = 0;
		remainder = ft_strjoin(remainder, buffer);
	}
	free(buffer);
	return (remainder);
}

char	*return_line(char *remainder)
{
	char	*line;
	int		i;

	i = 0;
	if (!*remainder)
		return (0);
	while (remainder[i])
	{
		if (remainder[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	line = (char *)malloc(i + 1);
	if (!line)
		return (0);
	line[i] = 0;
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
		line[i] = remainder[i];
	return (line);
}

char	*get_remainder(char *remainder)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (0);
	}
	str = (char *)malloc(ft_strlen(remainder) - i + 1);
	if (!str)
		return (0);
	i++;
	while (remainder[i])
		str[j++] = remainder[i++];
	str[j] = 0;
	free(remainder);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*remainder[4096];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	remainder[fd] = get_rough(remainder[fd], fd);
	if (!remainder[fd])
		return (0);
	ret = return_line(remainder[fd]);
	remainder[fd] = get_remainder(remainder[fd]);
	return (ret);
}
