#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *get_next_line(int fd){
	char *s = malloc(10000), *c = s;
	while(read(fd,c,1)>0 && *c++ != '\n');
	return c > s ? (*c = 0, s) : (free(s), NULL);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int fd;

		fd = open(argv[1], O_RDWR);
		printf("This is fd %d\n", fd);
		if (fd == -1)
		{
		printf("Failed to open file\n");
		return 1;
		}
		char *str;

		str = get_next_line(fd);
		printf("%s", str);
		free (str);
	}

}
