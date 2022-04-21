#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

int		how_much_char(int num)
{
	int rtn;
	if ( num == 0)
		return (0);
	if ( num < 0)
	{
		num = num * -1;
		rtn = 2;
	}
	if ( num > 0)
		rtn = 1;
	while (num > 0)
	{
		num = num / 10;
		rtn++;
	}
	return (rtn);
}



char *ft_itoa_base(int value, int base)
{
	char *rtn;
	char *base_array = {"0123456789ABCDEF"};
	int base_len;
	int world_len = how_much_char(value);

	char *rtn = malloc(sizeof(char) * world_len + 1);
	if (base <  2 || base > 16)
		return (NULL);
	if (base == 10 && value < 0)
	{
		int i = 0;
		rtn[i] = '-';
		value = value * -1;
		i++;
		while (world_len < 0)
		{
			rtn[i] == value % 10;
			i++;
			world_len--;
		}

	}


	return (rtn);
}


int main(void)
{



}