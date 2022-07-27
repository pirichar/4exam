#include "unistd.h"
#include "stdio.h"
#include "stdarg.h"
#include "limits.h"



void	ft_putchar(char c, int *sum){
	write(1, &c,1);
	(*sum)++;
}

void	ft_putstring(char *str, int *sum)
{
	int i = 0;
	while(str[i])
	{
		ft_putchar(str[i], sum);
		i++;
	}	
}

void	ft_putnbr(int num, int *sum)
{
	if (num == INT_MIN)
	{
		ft_putchar('-', sum);
		ft_putchar('2', sum);
		num = 147483648;
	}
	if (num < 0)
	{
		ft_putchar('-', sum);
		num = num *-1;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10, sum);
		ft_putnbr(num % 10, sum);
	}
	else
		ft_putchar(num + '0', sum);

}

void	ft_putnbrbase(unsigned int hex,int *sum, char *base, unsigned int base_l)
{
	char c;
	if (hex >= base_l)
		ft_putnbrbase(hex / base_l, sum, base, base_l);
	c = base[hex % base_l];
	ft_putchar(c, sum);
}


int	ft_printf(char *format, ...){

	va_list list;
	int sum;
	
	sum = 0;
	va_start(list, format);
	while(*format)
	{
		if (*format == '%')
		{
			format++;
			if(*format == 's')
				ft_putstring(va_arg(list, char *), &sum);
			else if(*format == 'd')
				ft_putnbr(va_arg(list, int), &sum);
			else if(*format == 'x')
			{
				//ft_putnbrbase(va_arg(list, unsigned int), &sum, "0123456789abcdef", 16);
				ft_putnbrbase(va_arg(list, unsigned int), &sum, "0123456789abcdef", 16);
			}
		}
		else
			ft_putchar(*format, &sum);
	format++;	
	}
	va_end(list);
	return (sum);
}


// int main(void)
// {

// 	char str[] = {"Allo ca va ?"};
// 	int 	i_min = INT_MIN;
// 	int	i_max = INT_MAX;
// 	unsigned int hex = 255;
// 	int realRtn;
// 	int myRtn;

// 	realRtn = printf("This is my string = %s\nThis is my i_min %d\nThis is my i_max %d\nThis is my hex %x\n ", str, i_min, i_max, hex);
// //	realRtn = printf("This is my string = %s\nThis is my i_min %d\nThis is my i_max %d\n", str, i_min, i_max);
// 	myRtn = ft_printf("This is my string = %s\nThis is my i_min %d\nThis is my i_max %d\nThis is my hex %x\n ", str, i_min, i_max, hex);
// //	myRtn = ft_printf("This is my string = %s\nThis is my i_min %d\nThis is my i_max %d\n", str, i_min, i_max);

// 	printf("This is realRtn = %d\nThis is myRtn = %d\n", realRtn, myRtn);
	
// }

int main(void)
{
	int i;
	int j;

	i = ft_printf("This is a string = %s\n", "0123456789");
	j = printf("This is a string = %s\n", "0123456789");
	printf("This is i = %d and this is j %d\n", i, j);
	
	i = ft_printf("This is a number = %d\n", INT_MIN);
	j = printf("This is a number = %d\n", INT_MIN);
	printf("This is i = %d and this is j %d\n", i, j);

	i = ft_printf("This is a number = %d\n", -400000);
	j = printf("This is a number = %d\n", -400000);
	printf("This is i = %d and this is j %d\n", i, j);
	i = ft_printf("This is a number = %d\n", 400000);
	j = printf("This is a number = %d\n", 400000);
	printf("This is i = %d and this is j %d\n", i, j);

	i = ft_printf("This is a number in hex = %x\n", 444444);
	j = printf("This is a number in hex = %x\n", 444444);
	printf("This is i = %d and this is j %d\n", i, j);

}

