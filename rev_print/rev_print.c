#include <stdio.h>



int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	int i = ft_strlen(argv[1]) - 1;
	if (argc == 2)
	{
		while(i >= 0)
		{
			printf("%c",argv[1][i]);
			i--;
		}
	}
	printf("\n");
}
