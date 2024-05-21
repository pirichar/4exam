#include "get_next_line.h"


char *get_next_line(int fd)
{
	char buf[BUFFER_SIZE+1];
	int count;
	static char* line;
	char* new_line;
	char *rtn;

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
	new_line = ft_strchr(line, '\n');
	if (!new_line || count == 0)
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

