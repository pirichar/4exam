#include <stdio.h>


int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			if((argv[1][i] > 64 && argv[1][i] < 91) ||
			(argv[1][i] > 96 && argv[1][i] < 123))
			{
				if((argv[1][i] > 109 && argv[1][i] < 123) ||
					(argv[1][i] > 78 && argv[1][i] < 91))
				{
					printf("%c",argv[1][i] - 13);
				}
				else
					printf("%c",argv[1][i] + 13);
			}
			else
			{
				printf("%c",argv[1][i]);
			}
			i++;
		}
	}

		printf("\n");
}
