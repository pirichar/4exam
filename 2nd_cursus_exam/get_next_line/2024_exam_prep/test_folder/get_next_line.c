#include "get_next_line.h"


char *get_next_line(int fd)
{
	char buf[BUFFER_SIZE+1];
	int count;
	static char* line;
	char* new_line;
	char *rtn;

	if (BUFFER_SIZE == 0)
		return(NULL);
	if (!line)
	{
		line = malloc(1);
		*line = '\0';
	}
	count = BUFFER_SIZE;
	while(count == BUFFER_SIZE)
	{
		if (ft_strchr(line, '\n'))
			break;
		count = read(fd, buf, BUFFER_SIZE);
		buf[count] = '\0';
		line = ft_strjoin(line, buf);
	}
	if (ft_strlen(line) == 0 || count == -1)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	if (count == 0)
		return(line);
	new_line = ft_strchr(line, '\n');
	if (!new_line)
	{
		rtn = line;
		line = NULL;
		return (rtn);
	}
	rtn = ft_substr(line, 0, new_line - line + 1);
	char *tmp = line;
	line = ft_substr(new_line, 1, ft_strlen(new_line));
	free(tmp);

	return(rtn);
}

/*
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
				char *rtn = get_next_line(fd);
				printf("This is my line %d \n------\n%s-------\n",i+1,rtn);
				free(rtn);
			}
	}
	else {
	printf("Please provide 2 arguments\n");
	}
}

*/