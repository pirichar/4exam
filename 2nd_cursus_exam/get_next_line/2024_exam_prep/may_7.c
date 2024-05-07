#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif


int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}
char *ft_strchr(char *str, char c)
{
	while(*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return(NULL);
}
char *ft_strjoin(char* s1, char* s2)
{
	int s1_len = ft_strlen(s1);
	int s2_len = ft_strlen(s2);
	char* rtn = malloc(sizeof(char) * (s1_len + s2_len + 1));
	
	//copy s1
	for(int i = 0; s1[i];i++)
		rtn[i] = s1[i];
	//copy s2
	for(int i = 0; s2[i];i++)
		rtn[ft_strlen(s1)+i] = s2[i];
	rtn[s1_len + s2_len + 1]  = '\0';
	//free s1
	if (s1)
		free(s1);
	return(rtn);
}

char *ft_substr(char *str, int start, int lenght)
{
	char *rtn;
	int size;

	size = lenght;
	if (start > lenght)
		size = 0;
	else if(start + lenght > ft_strlen(str))
		size = ft_strlen(str) - start;

	rtn = malloc(sizeof(char) * lenght + 1);
	for (int i = 0; i < size; i++)
		rtn[i] = str[start++];
	rtn[size] = '\0';
	return(rtn); 
}


char *get_next_line(int fd)
{
	char buffer[BUFFER_SIZE +1];
	static char *line;
	char *new_line;
	int count;
	char *rtn;

	if (!line)
		line = malloc(1);
	if (fd < 0)
		return(NULL);
	while(1)
	{
		if (ft_strchr(line, '\n'))
			break;
		count = read(fd, buffer, BUFFER_SIZE);
		if (count != BUFFER_SIZE)
		{
			if (count == 0)
			{
//				if (line)
//					free(line);
				return(NULL);
			}
			buffer[count] = '\0';
			rtn = ft_substr(buffer, 0, ft_strlen(buffer));
			free(line);
			return(rtn);
		}
		buffer[count] = '\0';
		line = ft_strjoin(line, buffer);
	}
	new_line = ft_strchr(line, '\n');
	rtn = ft_substr(line, 0, new_line - line + 1);
	free(line);
	line  = ft_substr(new_line,1, ft_strlen(new_line));
	return (rtn);
}



int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			printf("Can't open the file\n");
		else
			for(int i = 0; i  < 10; i++)
			{
				printf("This is my line %d \n------\n%s-------\n",i+1,get_next_line(fd));
			}
	}
	else {
	printf("Please provide 2 arguments\n");
	}
}
