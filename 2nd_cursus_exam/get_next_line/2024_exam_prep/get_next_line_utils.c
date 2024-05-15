#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

char *ft_strchr(char *str, char c)
{
	while(*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return(NULL);
}

char *ft_strjoin(char* s1, char* s2)
{
	int s1_len = ft_strlen(s1);
	int s2_len = ft_strlen(s2);
	char* rtn = malloc(sizeof(char) * (s1_len + s2_len + 1));

	for(int i = 0; s1[i];i++)
		rtn[i] = s1[i];
	for(int i = 0; s2[i];i++)
		rtn[s1_len+i] = s2[i];
	rtn[s1_len + s2_len]  = '\0';
	if (s1)
		free(s1);
	return(rtn);
}

char *ft_substr(char *str, int start, int lenght)
{
	char *rtn;
	int size;

	int str_len = ft_strlen(str);
	size = lenght;
	if (start > str_len)
		size = 0;
	else if(start + lenght > str_len)
		size = str_len - start;

	rtn = malloc(sizeof(char) * size + 1);
	for (int i = 0; i < size; i++)
		rtn[i] = str[start++];
	rtn[size] = '\0';
	return(rtn); 
}
