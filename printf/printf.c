#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_putchar(char c);
int ft_putstr(char *str);
void	ft_putnbr_base(size_t num, size_t base_len, char *base, int *sum);
void	ft_putnbr(long nb, int *sum);
void	ft_putcharo(char c, int *sum);

int	ft_printf(char *format, ...)
{
	int		sum;
	va_list	va_list;

	sum = 0;
	va_start(va_list, format);
	while(*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				sum += ft_putchar(va_arg(va_list, int));
			else if (*format == 's')
				sum += ft_putstr(va_arg(va_list, char*));
			else if (*format == 'x')
				ft_putnbr_base(va_arg(va_list, unsigned int), 16, "0123456789abcdef", &sum);
			else if (*format == 'd')
				ft_putnbr(va_arg(va_list, int), &sum);
//			else if (*format == '\0')
			else
			{
				sum += ft_putchar('%');
				sum += ft_putchar(*format);
			}
		}
		else
			sum += ft_putchar(*format);
		format++;
	}
	va_end(va_list);
	return (sum);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);	
}

int ft_putstr(char *str)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while(str[i])
	{
		sum += ft_putchar(str[i]);
		i++;
	}
	return (sum);
}

void	ft_putcharo(char c, int *sum)
{
	write(1,&c, 1);
	(*sum)++;
}

void	ft_putnbr(long nb, int *sum)
{
	if (nb == 0)
		ft_putcharo('0', sum);
	if (nb < 0)
	{
		ft_putcharo('-', sum);
		nb = nb * -1;
	}
	if (nb > 10)
	{
		ft_putnbr(nb / 10, sum);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		ft_putcharo(nb + '0', sum);	
	}
}

void	ft_putnbr_base(size_t num, size_t base_len, char *base, int *sum)
{
	char c;

	if (num >= base_len)
		ft_putnbr_base(num/base_len, base_len, base, sum);
	c = base[num % base_len];
	write(1, &c, 1);
	(*sum)++;
}



int main(void)
{
	int i;
	int j;

	i = ft_printf("This is a string = %s\n", "0123456789");
	j = printf("This is a string = %s\n", "0123456789");
	printf("This is i = %d and this is j %d\n", i, j);
	
	i = ft_printf("This is a number = %d\n", 400000);
	j = printf("This is a number = %d\n", 400000);
	printf("This is i = %d and this is j %d\n", i, j);

	i = ft_printf("This is a number = %d\n", -400000);
	j = printf("This is a number = %d\n", -400000);
	printf("This is i = %d and this is j %d\n", i, j);

	i = ft_printf("This is a number in hex = %x\n", 444444);
	j = printf("This is a number in hex = %x\n", 444444);
	printf("This is i = %d and this is j %d\n", i, j);

}

