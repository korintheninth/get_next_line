/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:01:38 by emamati           #+#    #+#             */
/*   Updated: 2024/02/01 16:04:43y emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 6

void b_zero(char *str, size_t size)
{
	int i;
	
	i = 0;
	while(i < size)
		str[i++] = 0;
}
int	str_len(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	cpy(char* dest, char* src, size_t size)
{
	int	i;

	i = 0;
	while(src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
}
void	cat(char* dest, char* src, size_t size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while(dest[i])
		i++;
	while(src[j] && j < size)
		dest[i++] = src[j++];
}
char	*get_next_line(fd)
{
	static char	buffer[4096][BUFFER_SIZE + 1];
	char	*ret;
	char	*hold;
	int		size;
	int		loop;
	int		i;
	int		j;
	
	loop = 1;
	size = 0;
	ret = NULL;
	hold = NULL;
	buffer[fd][BUFFER_SIZE] = 0;
	do{
		size++;
	}while (buffer[fd][size] && size < BUFFER_SIZE && buffer[fd][size - 1] != '\n');
	if(size != 0)
	{
		ret = (char *)malloc(size + 1);
		b_zero(ret, size + 1);
		cpy(ret, buffer[fd], size);
		b_zero(buffer[fd], size);
		if (ret[size - 1] == '\n')
		{
			j = 0;
			while(size < BUFFER_SIZE)
				buffer[fd][j++] = buffer[fd][size++];
			while (j < BUFFER_SIZE)
				buffer[fd][j++] = 0;
			return(ret);
		}
	}
	while (loop == 1)
	{	
		if (read(fd, buffer[fd], BUFFER_SIZE) == 0)
			return (NULL);
		i = 0;
		while (buffer[fd][i] && buffer[fd][i - 1] != '\n')
		{
			i++;
		}
		size += i;
		if (ret != 0)
		{
			hold = (char*)malloc(str_len(ret) + 1);
			b_zero(hold, str_len(ret) + 1);
			cpy(hold, ret, str_len(ret));
			free(ret);
			ret = (char *)malloc(str_len(hold) + size + 1);
			b_zero(ret, str_len(hold) + size + 1);
			cpy(ret, hold, str_len(hold));
			cat(ret, buffer[fd], i);
			b_zero(buffer[fd], i);
			free(hold);
		}
		else
		{
			ret = (char *)malloc(size + 1);
			b_zero(ret, size + 1);
			ret[size] = 0;
			cpy(ret, buffer[fd], i);
			b_zero(buffer[fd], i);
		}
		if (ret[str_len(ret) - 1] == '\n' || i < BUFFER_SIZE)
		{
			j = 0;
			while(i < BUFFER_SIZE)
				buffer[fd][j++] = buffer[fd][i++];
			while (j < BUFFER_SIZE)
				buffer[fd][j++] = 0;
			loop = 0;
		}
	}
	return(ret);
}

int main()
{
	int fd1 = open("testtxt.txt",O_RDONLY);
	int fd2 = open("testtxt2.txt", O_RDONLY);
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	for(int i = 0; i < 27; i++){
		printf("%s", get_next_line(fd1));
		//get_next_line(fd);
}
	for(int i = 0; i < 33; i++){
		printf("%s", get_next_line(fd2));
		//get_next_line(fd);
}
}