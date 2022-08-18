/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_vb_utils01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 00:55:12 by coder             #+#    #+#             */
/*   Updated: 2022/08/19 01:14:40 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	index_to_data(t_pushswap_data *ps_data)
{
	t_stack	*temp;
	int		i;

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
	t_pin	*pintemp;
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
	t_stack	*temp;

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
	t_stack	*temp;
	int		ret;

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

int	is_movable(int b_index, t_pushswap_data *ps_data)
{
	int		count;
	t_stack	*temp_b;
	t_stack	*temp_a;

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
