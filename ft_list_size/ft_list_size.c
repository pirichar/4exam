
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int rtn;

	rtn = 0;
	while(begin_list != NULL)
	{
		begin_list = begin_list->next;
		rtn++;
	}
	return (rtn);
}


int main(void)
{
	t_list *list;

	t_list *node;
	node = malloc(sizeof(t_list));
	t_list *node2;
	node2 = malloc(sizeof(t_list));
	t_list *node3;
	node3 = malloc(sizeof(t_list));

	list = node;
	node->data = (void *)1;
	node->next = node2;;

	node2->data = (void *)2;
	node2->next = node3;

	node3->data = (void *)4;
	node3->next = NULL;


	printf("THis is the return %d\n", ft_list_size(list));
}