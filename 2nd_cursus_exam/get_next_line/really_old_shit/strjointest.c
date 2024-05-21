#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;
	i = 0;

	while(str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1,char *s2)
{
	char *str;
	char *rtn;

	rtn = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	str = rtn;
	while(*s1 && s1)
	{
		*rtn = *s1;
		s1++;
		rtn++;
	}
	while(*s2 && s2)
	{
		*rtn = *s2;
		s2++;
		rtn++;
	}
	*rtn = '\0';
	return (str);
}

int main(void)
{
	char *s1 = {"Test"};
	char *s2 = {"DE FEU"};
	char *s3;

	printf("This is s1 before %s", s1);
	printf(" and this is s2 before %s\n", s2);
	s3 = ft_strjoin(s1,s2);
	printf("THis should be s3 = %s\n", s3);
	//free (s3);
}