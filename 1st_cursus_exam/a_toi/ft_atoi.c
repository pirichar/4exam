#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>




int ft_atoi(const char *str)
{
	int rtn;
	int i;
	int n;

	rtn = 0;
	i = 0;
	n = 1;
	while(str[i])
	{
		while(str[i] == ' ')
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if(str[i] == '-')
				n = -1;
			i++;
		}
		if(str[i] < '0' || str[i] > '9')
			return (0);	
		rtn = rtn * 10;
		rtn = rtn + str[i] - 48;
		i++;
	}
	return (rtn * n);

}





int main(int argc, char **argv)
{

	char *str = "   +-123";

	printf("%d\n",atoi(str));
	printf("%d\n", ft_atoi(str));	


}
