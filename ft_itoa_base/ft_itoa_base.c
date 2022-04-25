#include <stdio.h>
#include <stdlib.h>

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
	if ( num > 0)
		rtn = 1;
	if ( num < 0)
	{
		num = num * -1;
		rtn = 2;
	}
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
	int world_len = how_much_char(value);
	int i = 0;
	int neg = 0;
	printf("This is world_len %d\n", world_len);
	printf("This is value %d\n", value);

	rtn = malloc(sizeof(char) * world_len + 1);
	if (base <  2 || base > 16)
		return (NULL);
	if (base == 10 && value < 0)
	{
		neg = 1;
		rtn[i] = '-';
		value = value * -1;
		i++;
		while (value)
		{
			rtn[i] = base_array[value % base];
			// printf("This is rtn[i] = %c\n", rtn[i] );
			value = value / base;
			i++;
		}
	}
	else
	{
		while (value)
		{
			rtn[i] = base_array[value % base];
			// printf("This is rtn[i] = %c\n", rtn[i] );
			value = value / base;
			i++;
		}
	}
	rtn[world_len] = '\0';
	int str_size = ft_strlen(rtn);
	char tmp_char;
	//-0005
	//-5000
	//012345
	//word_len = 6;
	//5000
	//0005
	//01234
	//word_len = 5;
	if (neg == 1)
	{
		int j = 1;
		int tmp = world_len - 2;
		while(j < (str_size /2)  )
		{
			tmp_char = rtn[j];
			rtn[j] = rtn[tmp];
			rtn[tmp] = tmp_char;
			j++;
			tmp--;
		}
	}
	else
	{
		int j = 0;
		int tmp = world_len - 2;
		while(j < (str_size /2)  )
		{
			tmp_char = rtn[j];
			rtn[j] = rtn[tmp];
			rtn[tmp] = tmp_char;
			j++;
			tmp--;
		}
	}
	return (rtn);
}


int main(void)
{
	printf("FROM MAIN %s\n",ft_itoa_base(-5000,10));
	printf("FROM MAIN %s\n",ft_itoa_base(5000,10));
	printf("FROM MAIN %s\n",ft_itoa_base(342,16));
	printf("FROM MAIN %s\n",ft_itoa_base(16,16));
	printf("FROM MAIN %s\n",ft_itoa_base(12,16));
}
