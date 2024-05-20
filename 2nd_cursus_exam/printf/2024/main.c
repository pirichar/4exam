#include <stdio.h>
#include "printf.c"
#include <limits.h>

int main(void)
{
	int i;
	int j;

	i = ft_printf("MY   PRINTF - This is a string = %s\n", "0123456789");
	j = printf("REAL PRINTF - This is a string = %s\n", "0123456789");
	printf("This is MY PRINTF = %d and this is REALPRINTF %d\n", i, j);
	
	i = ft_printf("MY   PRINTF - This is a number = %d\n", INT_MIN);
	j = printf("REAL PRINTF - This is a number = %d\n", INT_MIN);
	printf("This is MY PRINTF = %d and this is REALPRINTF %d\n", i, j);

	i = ft_printf("MY   PRINTF - This is a number = %d\n", -400000);
	j = printf("REAL PRINTF - This is a number = %d\n", -400000);
	printf("This is MY PRINTF = %d and this is REALPRINTF %d\n", i, j);

	i = ft_printf("MY   PRINTF - This is a number = %d\n", 400000);
	j = printf("REAL PRINTF - This is a number = %d\n", 400000);
	printf("This is MY PRINTF = %d and this is REALPRINTF %d\n", i, j);

	i = ft_printf("MY   PRINTF - This is a number in hex = %x\n", 444444);
	j = printf("REAL PRINTF - This is a number in hex = %x\n", 444444);
	printf("This is MY PRINTF = %d and this is REALPRINTF %d\n", i, j);

}
