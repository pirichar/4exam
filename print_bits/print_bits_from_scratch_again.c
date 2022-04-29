#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void	print_bits(unsigned char octet)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if (octet & (1 << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
	write(1,"\n",1);
}

int ft_atoi(char *str)
{
	int i;
	int n;
	int res;

	i = 0;
	n = 1;
	res = 0;
	while(str[i])
	{
		if (str[i] == '-')
		{	n *= -1;
			i++;
		}
		while(str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + (str[i] - '0');
			i++;
		}
	}
	return (res * n);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int to_print = ft_atoi(argv[1]);
		printf("This is to print = %d\n",to_print);
		print_bits(to_print);
	}
}