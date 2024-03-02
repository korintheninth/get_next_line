#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

int		ft_strlen(char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *str1, char *str2);
char	*get_rough(char *remainder, int fd);
char	*return_line(char *remainder);
char	*get_remainder(char *remainder);
char	*get_next_line(int fd);
#endif
