#include <unistd.h>

void	ft_putchar(char c)
{
	write(1,&c,1);
}

int main(int argc, char **argv)
{

	int array[128] = {0};

	int i;
	int j;

	i = 0;
	j = 0;
	

	if (argc == 3)
	{
		while(argv[1][i])
		{
			if(array[(int)argv[1][i]] == 0)
			{
				ft_putchar(argv[1][i]);
				array[(int)argv[1][i]] = 1;
			}
			i++;
		}
		while(argv[2][j])
		{
			if(array[(int)argv[2][j]] == 0)
			{
				ft_putchar(argv[2][j]);
				array[(int)argv[2][j]] = 1;
			}
			j++;
		}
	}
	ft_putchar('\n');

}

