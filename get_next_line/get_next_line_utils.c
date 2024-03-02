#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	if (str == NULL || c == '\0')
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*res;

	if (!str1)
	{
		str1 = malloc(sizeof(char));
		*str1 = '\0';
	}
	if (!str1 || !str2)
		return (NULL);
	res = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (*(str1 + ++i))
		*(res + i) = *(str1 + i);
	j = 0;
	while (*(str2 + j))
		*(res + i++) = *(str2 + j++);
	*(res + i) = '\0';
	free(str1);
	return (res);
}
