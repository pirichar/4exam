#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnumber(int nb)
{
	long n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnumber( n / 10);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar(n + '0');
}
//1001
//01234
int	ft_atoi(char *str)
{
	int rtn;
	int i;
	int negative;
	
	i = 0;
	negative = 1;
	rtn = 0;
	if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		rtn = rtn * 10;
		rtn = rtn + str[i] - '0';
		i++;
	}
	return (rtn * negative);
}

int main(int argc, char **argv)
{
	int nb;

	if (argc == 2)
	{
		nb = ft_atoi(argv[1]);
		printf("This is nb from printf %d\n", nb);
		ft_putnumber(nb);
	}
}