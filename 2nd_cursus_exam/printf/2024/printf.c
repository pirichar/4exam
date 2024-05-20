#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

/*
Assignment name : ft_printf
Expected files : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end

Write a function named ft_printf that will mimic the real printf but it will manage only the following conversions:

s (string), d (decimal) and x (lowercase hexademical).

Your function must be declared as follows:
int ft_printf(const char *, ... );

Examples of the function output:

call: ft_printf("%s\n", "toto"); out: toto$

call: ft_printf("Magic %s is %d", "number", 42); out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42); out: Hexadecimal for 42 is 2a$
*/

static int ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
}

static int ft_putstr(char *str)
{
	int rtn = 0;
	if (!str)
		str = "(null)";
	while(*str)
	{
		rtn += ft_putchar(*str++);
	}
	return(rtn);
}
static void ft_putnbr(int nbr, int *sum)
{
	if (nbr == INT_MIN)
	{
		*sum += ft_putchar('-');
		*sum += ft_putchar('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		*sum+= ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, sum);
		ft_putnbr(nbr % 10, sum);
	}
	else {
		*sum += ft_putchar(nbr + '0');
	}
}

static void ft_putnbro(int nbr, int base_len, char *base, int *sum)
{
	char c;

	if (nbr > base_len)
		ft_putnbro(nbr / base_len, base_len, base, sum);
	c = base[nbr % base_len];
	*sum += ft_putchar(c);
}

int ft_printf(const char *fmt, ... )
{
	va_list ap;
	int d;
	char *str;
	unsigned int x;
	int rtn = 0;

	va_start(ap, fmt);
	while(*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 's')
			{
   				 str = va_arg(ap, char *);
				 rtn += ft_putstr(str);
			}
			else if (*fmt == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr(d, &rtn);
			}
			else if (*fmt == 'x')
			{
				x = va_arg(ap, unsigned int);
				ft_putnbro(x, 16, "0123456789abcdef", &rtn);
			}
		}
		else {
			rtn += ft_putchar(*fmt);
		}
		fmt++;
	}
	va_end(ap);
	return (rtn);
}

#include <stdio.h>

int main(void)
{
	int i;
	int j;

	i = ft_printf("This is a string = %s\n", "0123456789");
	j = printf("This is a string = %s\n", "0123456789");
	printf("This is i = %d and this is j %d\n", i, j);
	
	i = ft_printf("This is a string = %s\n", (char*)NULL);
	j = printf("This is a string = %s\n", (char*)NULL);
	printf("This is i = %d and this is j %d\n", i, j);
	
	i = ft_printf("This is a number = %d\n", INT_MIN);
	j = printf("This is a number = %d\n", INT_MIN);
	printf("This is i = %d and this is j %d\n", i, j);

	i = ft_printf("%d", -400000);
	j = printf("%d", -400000);
	printf("This is i = %d and this is j %d\n", i, j);
	i = ft_printf("This is a number = %d\n", 400000);
	j = printf("This is a number = %d\n", 400000);
	printf("This is i = %d and this is j %d\n", i, j);

	i = ft_printf("This is a number in hex = %x\n", 444444);
	j = printf("This is a number in hex = %x\n", 444444);
	printf("This is i = %d and this is j %d\n", i, j);

}

