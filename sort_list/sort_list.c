#include "list.h"

int ascending(int a, int b)
{
	return (a <= b);
}

t_list *sort_list(t_list *lst, int (*cmp)(int,int))
{
	int swap;
	t_list *tmp;

	//make a copy of the pointer lst provided by the user
	//we will use it at the end to point at the first element in memory
	//of our list
	tmp = lst;
	while(lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			//here we reset and start from the bottom
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}


int main(void)
{
	t_list *list;

	t_list *node;
	node = malloc(sizeof(t_list));
	t_list *node1;
	node1 = malloc(sizeof(t_list));
	t_list *node2;
	node2 = malloc(sizeof(t_list));	
	t_list *node3;
	node3 = malloc(sizeof(t_list));
	t_list *node4;
	node4 = malloc(sizeof(t_list));


	list = node;
	node->data = 5;
	node->next = node1;

	node1->data = 4;
	node1->next = node2;

	node2->data = 3;
	node2->next = node3;

	node3->data = 2;
	node3->next = node4;

	node4->data = 1;
	node4->next = NULL;


	t_list *tmp;

	tmp = list;
	while(tmp)
	{
		printf("Data = %d\n", tmp->data);
		tmp =  tmp->next;
	}

	tmp = sort_list(tmp, &ascending);
	while(tmp)
	{
		printf("Data = %d\n", tmp->data);
		tmp =  tmp->next;
	}
}
