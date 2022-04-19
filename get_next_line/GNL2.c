#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#undef BUFFER_SIZE
#define BUFFER_SIZE 1

int ft_strlen(char *str);
char *ft_strjoin(char *s1,char *s2);

char *	get_next_line(int fd)
{
	char *stack = NULL;
	int ret;
	char *buffer;
	int i = 0;

	ret = BUFFER_SIZE;
	if (fd < 0)
		return (NULL);
	while (ret == BUFFER_SIZE)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buffer[ret] = '\0';
		stack = ft_strjoin(stack, buffer);
		free (buffer);
	if (stack[i] == '\n')
			break;
		i++;
	}
	return (stack);
}

int	ft_strlen(char *str)
{
	int i = 0;
	while(str && str[i])
		i++;
	return i;
}

char *ft_strjoin(char *s1,char *s2)
{
	char *str;
	char *rtn;
	char *s1C;

	s1C = s1;
	rtn = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	str = rtn;
	while(s1 && *s1)
	{
		*rtn = *s1;
		s1++;
		rtn++;
	}
	while(s2 && *s2)
	{
		*rtn = *s2;
		s2++;
		rtn++;
	}
	*rtn = '\0';
	if (s1C)
		free (s1C);
	return (str);
}

 int main(void)
 {
	 int fd;
	 char *print;


	 fd = open("./test_files/emptye.txt", O_RDONLY);
	for(int i = 0; i < 6; i++)
	 {
		print = get_next_line(fd);
	 	printf("%s", print);
	 	free (print);
	 }
 }