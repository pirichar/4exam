#include "get_next_line.h"

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