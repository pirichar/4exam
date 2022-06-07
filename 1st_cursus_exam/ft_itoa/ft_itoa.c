#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return(i);
}


void rev_string(char *str)
{

	int i = 0;
	int len = ft_strlen(str) -1;
	char tmp;
	printf("This is str before the reverse in rev_string %s\n", str);
	if (str[i] == '-')
		i++;
	while(i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	printf("This is the str after the reverse %s\n", str);
}


int	how_much_chars(int nb)
{
	int rtn;

	rtn = 1;
	if (nb < 0)
	{
		rtn = 2;
		nb = nb * -1;	
	}
	while (nb > 9)
	{
		nb = nb / 10;
		rtn++;
	}
	return (rtn);
}

char *ft_itoa(int nbr)
{
	char *rtn;
	int nb;
	int count = how_much_chars(nbr);
	printf("This is the count of my nbr %d\n", count);
	int i = 0;
	int countcp = count;
	rtn = malloc(sizeof(char) * count + 1);
	if (nbr < 0)
	{
		rtn[i] = '-';
		nbr = nbr * -1;
		i++;
	}
	while (nbr)
	{
		rtn[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	rtn[count] = '\0';
	rev_string(rtn);
	return(rtn);
}


int ft_atoi(char *str)
{
	int i = 0;
	int neg = 1;
	int rtn = 0;

	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while(str[i])
	{
		rtn = rtn * 10 + str[i] - '0';
		i++;
	}
	return (neg * rtn);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = ft_atoi(argv[1]);
		printf("This is i %d\n", i);
		printf("This is the return %s\n", ft_itoa(i));
	}
	else
		printf("Need more arguments");

}