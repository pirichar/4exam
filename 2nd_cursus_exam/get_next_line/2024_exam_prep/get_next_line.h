#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#endif 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

int ft_strlen(char *str);

char *ft_strchr(char *str, char c);

char *ft_strjoin(char* s1, char* s2);

char *ft_substr(char *str, int start, int lenght);

char *get_next_line(int fd);