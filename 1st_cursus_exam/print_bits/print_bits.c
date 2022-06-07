#include <stdio.h>
#include <unistd.h>

//pour masquer des bits la valeur du masque doit etre a 0
// avec la valeur de 1 je vais pouvoir voir la vrai valeur recherchée
/*
	1100 0010		nombre donné
	0000 0010		masque
	0000 0010		output
*/
// void	print_bits(unsigned char octet)
// {
// 	int i = 7;
// 	while (i >= 0)
// 	{
// 		if (octet & (1 << i))
// 			printf("1");
// 		else
// 			printf("0");
// 		i--;
// 	}
// printf("\n");
// }







// void	print_bits(unsigned char octet)
// {
// 	if (octet >= 2)
// 	{
// 		print_bits(octet / 2);
// 	}
// 	printf("%d",(octet % 2));
// }
void	print_bits(unsigned char octet)
{
	int i = 7;
	while ( i >= 0)
	{
		if (octet & (1 << i))
			write(1,"1",1);
		else
			write(1,"0",1);
		i--;
	}
	printf("\n");
}












int	ft_atoi(char *str)
{
	int rtn;
	int n;
	int i;

	i = 0;
	rtn = 0;
	n = 1;
	while(str[i] == ' ')
		i++;
	if(str[i] == '-')
	{
		n =  -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		rtn = rtn * 10;
		rtn = rtn + (str[i] - '0');
		i++;
	}
	return (rtn * n);
}


int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int c;
		c = ft_atoi(argv[1]);
		printf("This is the number %d\n", c);
		print_bits(c);
		printf("This is the bit result : ");
	}
	else
		printf("Need more then one argument\n");
}

