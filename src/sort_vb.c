/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_vb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:30:48 by coder             #+#    #+#             */
/*   Updated: 2022/08/17 02:54:53 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
** set's all indexes in the stack to their right place.
*/
void	index_to_data(t_pushswap_data *ps_data)
{
	t_stack *temp;

	int	i;
	i = 0;
	temp = ps_data->head_a;
	while (temp)
	{
		while (i < ps_data->ele_count)
		{
			if (temp->num == ps_data->lut[i])
				temp->index = i;
			i++;
		}
		i = 0;
		temp = temp->next;
	}
}

/*
** initializes all is_indexed variables to reflect their right status;
*/
void	pin_to_data(t_pushswap_data *ps_data)
{
	t_pin 	*pintemp;
	t_stack	*stack;

	stack = ps_data->head_a;
	pintemp = ps_data->pin_head;
	while (stack)
	{
		while (pintemp)
		{
			if (stack->num == pintemp->num)
				stack->is_indexed = 1;
			pintemp = pintemp->next;
		}
		pintemp = ps_data->pin_head;
		stack = stack->next;
	}
}

int	stack_is_indexed(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	while (temp)
	{
		if (!temp->is_indexed)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	get_stack_size(t_stack *stack)
{
	t_stack *temp;
	int ret;

	temp = stack;
	ret = 0;
	if (!temp)
		return (-1);
	while (temp)
	{
		temp = temp->next;
		ret++;
	}
	return (ret);
}

int is_movable(int b_index, t_pushswap_data *ps_data)
{
	int count;
	t_stack *temp_b;
	t_stack *temp_a;

	temp_b = ps_data->head_b;
	temp_a = ps_data->head_a;
	count = 0;
	while (count++ < b_index)
		temp_b = temp_b->next;
	count = 0;
	while (temp_a)
	{
		if (((temp_a->index) + 1 == temp_b->index)
			|| ((temp_a->index) - 1 == temp_b->index))
				return (count);
		count++;
		temp_a = temp_a->next;
	}
	return (-1);
}

int	get_moves_to_pa(int a_index, int b_index, t_svb self)
{
	int	moves_a;
	int moves_b;

	moves_a = -1;
	moves_b = -1;
	if (a_index <= self.size_a / 2)
		moves_a = a_index;
	else
		moves_a = self.size_a - a_index;
	if (b_index <= self.size_b / 2)
		moves_b = b_index;
	else
		moves_b = self.size_b - b_index;
	return (moves_a + moves_b);
}

int	get_best_to_mv(t_pushswap_data *ps_data, t_svb self)
{
	int	b_index;
	int	temp;
	int min;
	int a_index;

	b_index = 0;
	temp = -1;
	min = -1;
	while (b_index < self.size_b)
	{
		a_index = is_movable(b_index, ps_data);
		if (a_index >= 0)
		{
			if (temp < 0)
			{
				temp = get_moves_to_pa(a_index, b_index, self);
				min = b_index;
			}
			else if (temp < get_moves_to_pa(a_index, b_index, self))
				{
				min = b_index;
				temp = get_moves_to_pa(a_index, b_index, self);
				}
		}
		b_index++;
	}
	return (min);
}

int	get_best_a(t_pushswap_data *ps_data, t_svb self)
{
	return (is_movable(self.best_b, ps_data));
}

t_svb init_svb(t_pushswap_data *ps_data)
{
	t_svb ret;
	ret.index = 0;
	ret.size_a = get_stack_size(ps_data->head_a);
	printf ("size_a: %d\n", ret.size_a);
	ret.size_b = get_stack_size(ps_data->head_b);
	printf ("size_b: %d\n", ret.size_b);
	ret.best_b = get_best_to_mv(ps_data, ret);
	printf ("best_b: %d\n", ret.best_b);
	ret.best_a = get_best_a(ps_data, ret);
	printf ("best_a: %d\n", ret.best_a);
	ret.moves_a =
	return (ret);
}

int case02(t_pushswap_data *ps_data)
{
	t_svb svb;
	svb = init_svb(ps_data);

	printf ("\n<<<<<< A >>>>>>\n");
	print_list (ps_data->head_a);
	printf ("\n<<<<<< B >>>>>>\n");
	print_list (ps_data->head_b);
	exit (2);

	return (1);
}

int case01(t_pushswap_data *ps_data)
{
	t_stack	*temp;

	temp = ps_data->head_a;
	if (temp->next && ((temp->is_indexed && !temp->next->is_indexed) || (temp->next->is_indexed && !temp->is_indexed)))
	{
		if (temp->next->index + 1 == temp->index)
		{
			temp->next->is_indexed = 1;
			temp->is_indexed = 1;
			mv(SA, ps_data);
			return (1);
		}
	}
	if (!temp->is_indexed)
	{
		mv(PB, ps_data);
		return (1);
	}
	mv(RA, ps_data);
	return (1);

}

void sort_vb(t_pushswap_data *ps_data)
{
	int	run;

	run = 1;
	set_pin(ps_data);
	pin_to_data(ps_data);
	index_to_data(ps_data);
	while (run)
	{
		if (!stack_is_indexed(ps_data->head_a))
		{
			case01(ps_data);
			continue;
		}
		if (ps_data->head_b)
		{
			case02(ps_data);
			continue;
		}
		run = 0;
	}
}
