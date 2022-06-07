#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

// char *ft_getnextline(int fd) 
// {
//     char *s = malloc(10000), *c = s;
//     while (read(fd, c, 1) > 0 && *c++ != '\n');
//     return c > s ? (*c = 0, s) : (free(s), NULL);
// }
char *ft_getnextline(int fd)
{
	if (BUFFER_SIZE > 0)
	{
		char *s = malloc(10000), *c = s;
		while (read(fd, c, 1) > 0 && *c++ != '\n');
		return c > s ? (*c = 0, s) : (free(s), NULL);
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int fd = open(argv[1],O_RDONLY);
		if (fd == -1)
		{
			printf("Failed to open the file");
			return (1);
		}
		int nb = atoi(argv[2]);
		int i = 0;
		while(i < nb)
		{
			char *to_print = ft_getnextline(fd);
			printf("%s\n", to_print);
			free(to_print);
			i++;
		}
	}
	else
		printf("Usage : \n argv[1] == file to open\n argv[2] = nb of line to read\n");

}
