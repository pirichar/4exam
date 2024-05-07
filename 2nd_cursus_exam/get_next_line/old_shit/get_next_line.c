#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/*don't forget to BUFFER_SIZE
 * Write your own strjoinfree
 *
 * Look into fd 
 * iS there a new line ?
 * No ; Keep lookin
 * Yes; Break out;
 * */


#define BUFFER_SIZE 20000

int	 ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_free_stuff(char *saved, char *new_line);

char	*get_next_line(int fd)
{
	static char 	*saved = NULL;
	char 		*buff;
	char 		*rtn;
	int 		ret;
	char		*new_line;

	ret = BUFFER_SIZE;
	while(ret == BUFFER_SIZE)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buff[ret] = '\0';
		saved = ft_strjoin(saved, buff);
		new_line = ft_strchr(saved, '\n');
		if (new_line)
			break;	
	}
//	if(new_line)
//	{
		rtn = ft_substr(saved, 0, (new_line - saved + 1));
		saved = ft_free_stuff(saved, new_line);
//	}		
	return (rtn);
}

int main(void)
{

	int fd;
	char *print;

	fd = open("./test_files/test.txt", O_RDONLY);

	for (int i = 0; i < 3; i++)
	{
		print = get_next_line(fd);
		printf("%s", print);
		free (print);
	}

}

char *ft_free_stuff(char *saved, char *new_line)
{
	char	*tmp;
	tmp = ft_substr(saved, 1, ft_strlen(new_line));
	free(saved);
	saved = tmp;
	return (saved);
}


char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	i = 0;

	rtn = malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		rtn[i] = s[start + i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}





char	*ft_strchr(const char *s, int c)
{
	unsigned char c2;
	c2 = c;
	while(s && *s)
	{
		if(*s == c)
			return ((char *)s);
		else
			s++;
	}
	return (NULL);
}


int ft_strlen(char *str)
{
	int i = 0;
	while(str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *rtn;
	int i = 0;
	int j = 0;

	rtn = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	while(s1 && s1[i])
	{
		rtn[i] = s1[i];
		i++;
	}
	while(s2 && s2[j])
	{
		rtn[i] = s2[j];
		i++;
		j++;
	}
	rtn[i] = '\0';
	if (s1)
		free(s1);
	return (rtn);
}




