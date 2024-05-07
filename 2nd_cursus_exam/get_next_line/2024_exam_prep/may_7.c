#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif


int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

char *ft_strjoin(char* s1, char* s2)
{
	int s1_len = ft_strlen(s1);
	int s2_len = ft_strlen(s2);
	char* rtn = malloc(sizeof(char) * (s1_len + s2_len + 1));
	
	//copy s1
	for(int i = 0; s1[i];i++)
		rtn[i] = s1[i];
	//copy s2
	for(int i = 0; s2[i];i++)
		rtn[ft_strlen(s1)+i] = s2[i];
	rtn[s1_len+s2_len] = '\0';
	//free s1
	if (s1)
		free(s1);
	return(rtn);
}

char *ft_substr(char *str, int start, int lenght)
{
	char *rtn;
	int size;

	size = lenght;
	if (start > lenght)
		size = 0;
	else if(start + lenght > ft_strlen(str))
		size = ft_strlen(str) - start;

	rtn = malloc(sizeof(char) * lenght + 1);
	for (int i = 0; i < size; i++)
		rtn[i] = str[start++];
	rtn[size] = '\0';
	return(rtn); 
}


char *get_next_line(int fd)
{
	char buffer[BUFFER_SIZE +1];
	static char *rtn;
	char *new_line;

	if (fd < 0)
		return(NULL);
	while(1)
	{

	}
	return (rtn);

}

int main(void)
{

	char *s1 = "Hello";
	char *s2 = ft_substr(s1, 1,3);
	printf("This is s1[%s] this is s2[%s]", s1,s2);
}