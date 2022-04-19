#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	int array[256] = {0};
	int i;
	int j;

	i = 0;
	j = 0;
	
	if (argc == 3)
	{
		while(argv[2][i])
		{
			if (array[(int)argv[2][i]] == 0)
				array[(int)argv[2][i]] = 1;
			i++;
		}
		while(argv[1][j])
		{
			if (array[(int)argv[1][j]] == 1)
			{
				array[(int)argv[1][j]] = 2;
				ft_putchar(argv[1][j]);
			}
			j++;
		}
	}
	ft_putchar('\n');
}



