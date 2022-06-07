#include <stdio.h>


int main(int argc, char **argv)
{
	int i;
	
	i = 0;
	if (argc == 2)
	{
		//clear out the spaces at first
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
		while(argv[1][i])
		{
			if (argv[1][i] == ' '  || argv[1][i] == '\t')
			{
				if(argv[1][i + 1] > 32 && argv[1][i + 1] != '\0')
					printf("%c", argv[1][i]);
			}
			else if (argv[1][i] != ' ' || argv[1][i] != '\t')
				printf("%c", argv[1][i]);
			i++;
		}
	}
	printf("\n");
}
