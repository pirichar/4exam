#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int ft_strlen(char* str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}


char* ft_strjoin(char* s1, char* s2)
{
	int s1_len = ft_strlen(s1);
	int s2_len = ft_strlen(s2);
	char *rtn = NULL;

	rtn = malloc(sizeof(char) * (s1_len + s2_len + 1));
	for (int i = 0; i < s1_len; i++)
		rtn[i] = s1[i];
	for (int i = 0;i < s2_len;i++)
		rtn[s1_len + i] = s2[i];
	rtn[s1_len + s2_len + 1] = '\0';
	free(s1);
	return (rtn);
}

char* ft_substr(char* str, int start, int lenght)
{
	int size;
	char *rtn;

	int str_len = ft_strlen(str);
	size = lenght;
	if (start > str_len)
		size = 0;
	else if (start + lenght > str_len)
		size = str_len - start;

	rtn = malloc(sizeof(char) * str_len + 1 );
	for (int i = 0; i < size; i++)
		rtn[i] = str[start++];
	rtn[size] = '\0';
	return (rtn);
}

char *ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

char* get_next_line(int fd)
{
	char buf[BUFFER_SIZE + 1];
	static char *line;
	char *new_line;
	char *rtn = NULL;
	int	count;
	int state = 0;

	if (line == NULL)
		line = malloc(sizeof(char));
	while(1)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1 || count == 0) // we  have red the whole file 
		{
			state = 1;
			break;
		}
		buf[count] = '\0';
		line = ft_strjoin(line, buf);
		if (ft_strchr(line, '\n'))
		{
			new_line = ft_strchr(line, '\n');
			state = 0;
			break;
		}
	}
	if (state == 1) 	// we had a problem
	{
		if (count == -1)
		{
			return (NULL);
			free(line);
		}
	}
	if(state == 0) // everything went fine
	{
		//create the line to return
		rtn = ft_substr(line, 0, (new_line - line) + 1);
		//set the new 
		char *tmp = line;
		line = ft_substr(new_line, 1,ft_strlen(new_line));
		free(tmp);
	}
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
			for(int i = 0; i  < 4; i++)
			{
				printf("This is my line %d \n------\n%s-------\n",i+1,get_next_line(fd));
			}
	}
	else {
	printf("Please provide 2 arguments\n");
	}
}
