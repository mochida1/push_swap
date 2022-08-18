/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_vb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:30:48 by coder             #+#    #+#             */
/*   Updated: 2022/08/18 02:04:26 by coder            ###   ########.fr       */
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

/*
** gets the index of the !!STACK!! of the best element to move
*/
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

int	calc_moves_quant(int best_index, int stack_sz)
{
	if (best_index < stack_sz / 2)
		return (best_index);
	else
		return (stack_sz - best_index);
}

int	get_lut_from (int best_x, t_stack *stack_x)
{
	int			i;
	t_stack	*temp;

	temp = stack_x;
	i = 0;
	while (i != best_x)
	{
		temp = temp->next;
		i++;
	}
	return (temp->index);
}

int	check_if_last(t_stack *stack, int index)
{
	t_stack *temp;

	temp = stack;
	while (temp)
	{
		if (!temp->next && temp->index == index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	rotate_till_bot(t_stack *stack, int index, t_pushswap_data *ps_data)
{
	while (check_if_last(stack, index))
		mv (RA, ps_data);
}

void	rrrotate_till_bot(t_stack *stack, int index, t_pushswap_data *ps_data)
{
	while (check_if_last(stack, index))
		mv (RA, ps_data);
}

int	move_best_b (t_pushswap_data *ps_data, t_svb svb)
{
	int rrrotation;

	// if (!svb.best_b)
	// {
	// 	ps_data->head_b->is_indexed = 1;
	// 	mv(PA, ps_data);
	// 	return (1);
	// }
	rrrotation = 0;
	if (svb.best_b < ((svb.size_b) / 2))
		rrrotation = 1;
	if (rrrotation)
		while (ps_data->head_b->index != svb.index_b)
			mv (RRB, ps_data);
	while (ps_data->head_b->index != svb.index_b)
			mv (RB, ps_data);
	ps_data->head_b->is_indexed = 1;
	mv(PA, ps_data);
	printf ("\n______________________\n");
	print_list(ps_data->head_a);
	return (1);
}

int	move_best_a (t_pushswap_data *ps_data, t_svb svb)
{
	int rrrotation;
	int should_be_on_bot;

	if (!svb.best_a)
		return (0);
	rrrotation = 0;
	should_be_on_bot = 0;
	if (svb.best_a > svb.best_b)
		should_be_on_bot = 1;
	if (svb.best_a < ((svb.size_a + should_be_on_bot) / 2))
		rrrotation = 1;
	if (!should_be_on_bot && !rrrotation)
		while (ps_data->head_a->index != svb.index_a)
			mv (RA, ps_data);
	else if (!should_be_on_bot && rrrotation)
		while (ps_data->head_a->index != svb.index_a)
			mv (RRA, ps_data);
	else if (should_be_on_bot && !rrrotation)
		rotate_till_bot(ps_data->head_a, svb.index_a, ps_data);
	else if (should_be_on_bot && rrrotation)
		rrrotate_till_bot(ps_data->head_a, svb.index_a, ps_data);
	return (1);
}

t_svb init_svb(t_pushswap_data *ps_data)
{
	t_svb ret;

	ret.size_a = get_stack_size(ps_data->head_a);
	ret.size_b = get_stack_size(ps_data->head_b);
	ret.best_b = get_best_to_mv(ps_data, ret);
	ret.best_a = get_best_a(ps_data, ret);
	ret.dist_a = calc_moves_quant(ret.best_a, ret.size_a);
	ret.dist_b = calc_moves_quant(ret.best_b, ret.size_b);
	ret.index_a = get_lut_from (ret.best_a, ps_data->head_a);
	ret.index_b = get_lut_from (ret.best_b, ps_data->head_b);
	return (ret);
}

int	i_should_rrr(t_pushswap_data *ps_data)
{
	t_stack	*temp;
	int	i;

	i = 0;
	temp = ps_data->head_a;
	while (temp->index)
	{
		temp = temp->next;
		i++;
	}
	if (i < ((ps_data->ele_count - 1) / 2))
		return (0);
	return (1);
}

int case03(t_pushswap_data *ps_data)
{
	if (i_should_rrr(ps_data))
		while (ps_data->head_a->index)
			mv(RRA, ps_data);
	else
		while (ps_data->head_a->index)
			mv(RA, ps_data);
	return (1);
}

int case02(t_pushswap_data *ps_data)
{
	t_svb svb;

	while (ps_data->head_b)
	{
	svb = init_svb(ps_data);
	move_best_a (ps_data, svb);
	move_best_b (ps_data, svb);
	}
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
			// printf ("\n----------------\n");
			// print_list(ps_data->head_a);
			// printf ("\n****************\n");
			continue;
		}
		case03(ps_data);
		run = 0;
	}
}
