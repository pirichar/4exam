#include <stdio.h>

//pour masquer des bits la valeur du masque doit etre a 0
// avec la valeur de 1 je vais pouvoir voir la vrai valeur recherchée
/*
	1100 0010		nombre donné
	0000 0010		masque
	0000 0010		output
*/
void	print_bits(unsigned char octet)
{
	int i = 7;
	while (i <= 0)
	{
		if (octet & (1 << i))
			printf("1");
		else
			printf("0");
		i--;
	}
printf("\n");
}

int main(void)
{
	char c;
	c = 9;

	print_bits(c);
}

