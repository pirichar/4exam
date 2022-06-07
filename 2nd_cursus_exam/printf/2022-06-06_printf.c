#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void	ft_putcharo(char c, int *sum)
{
	write(1, &c,1);
	(*sum)++;
}

void	ft_putstring(char *str, int *sum)
{
	int i = 0;
	while(str[i])
	{
		ft_putcharo(str[i], sum);
		i++;
	}
}

void	ft_putnbr(int nb, int *sum)
{
	long n = nb;
	if (n == 0)
		ft_putcharo('0', sum);
	if (n < 0)
	{
		ft_putcharo('-', sum);
		n = n * -1;
	}
	if (n > 9)
	{	
		ft_putnbr(n/10, sum);
		ft_putnbr(n%10, sum);
	}
	else
		ft_putcharo(nb + '0', sum);
}

void	ft_putnbro(unsigned int num, char *base, unsigned int base_len, int *sum)
{
	char c;

	if (num > base_len)
		ft_putnbro(num / base_len, base, base_len, sum);
	c = base[num % base_len];
	ft_putcharo(c, sum);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int sum = 0;
	char *s;
	int d;
	unsigned int hex;

	va_start(ap, format);
	while(*format)
	{
		if (*format == '%')
		{
			format++;
			if(*format == 's')
			{
				s = va_arg(ap, char *);
				ft_putstring(s, &sum);	
			}
			else if(*format == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr(d, &sum);
			}
			else if (*format == 'x')
			{
				hex = va_arg(ap, unsigned int);
				ft_putnbro(hex,"0123456789abcdef", 16,  &sum);	
			}
		}
		else
			ft_putcharo(*format, &sum);
	format++;
	}
	va_end(ap);
	return (sum);
}



int main(int argc, char **argv)
{
	if (argc == 4)
	{
	int myprint;
	int realprint;

/*	char a_string[100] = "Indeed I am a string";
	int an_int = -654321;
	unsigned int an_hex = 44;*/
	char *a_string = argv[1];
	int an_int = atoi(argv[2]);
	unsigned int an_hex = atoi(argv[3]);		
	
	myprint = ft_printf("Hello\n");
	realprint = printf("Hello\n");
	printf("This is myprint =%d\nThis is realprint =%d\n",myprint,realprint);
	myprint = ft_printf("This is a string %s\n", a_string);
	realprint = printf("This is a string %s\n", a_string);
	printf("This is myprint = %d\nThis is realprint = %d\n",myprint,realprint);
	myprint = ft_printf("This is an int  %d\n", an_int);
	realprint = printf("This is an int  %d\n", an_int);
	printf("This is myprint = %d\nThis is realprint = %d\n",myprint,realprint);
	myprint = ft_printf("This is an HEX  %x\n", an_hex);
	realprint = printf("This is an HEX  %x\n", an_hex);
	printf("This is myprint = %d\nThis is realprint = %d\n",myprint,realprint);
	}
	else
	{
	printf("Usage :\n argv[0] = ./a.out\n argv[1] = 'A STRING'\n argv[2] = 'AN INT positive or negative'\n argv[3] = 'a positive unsigned int to convert to hex\n'");
	}	
return (0);
}
