# include "../headers/push_swap.h"

void	print_list(t_stack *head_a) //deletar!
{
	t_stack *temp = head_a;

	while (temp)
	{
		printf("Curr:%p\n", temp);
		printf("Curr->next:%p\n", temp->next);
		printf("Curr->prev:%p\n", temp->prev);
		printf("I:%d, arg:%d PINned:%d\n\n", temp->stack_order, temp->num, temp->is_indexed);
		temp = temp->next;
	}

}
