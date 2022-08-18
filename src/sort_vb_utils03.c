/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_vb_utils03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:08:15 by coder             #+#    #+#             */
/*   Updated: 2022/08/19 01:15:31 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	check_if_last(t_stack *stack, int index)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (!temp->next && temp->index == index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	rr_till_bot(t_stack *stack, int index, t_pushswap_data *ps_data)
{
	while (check_if_last(stack, index))
		mv (RA, ps_data);
}

void	rrrr_till_bot(t_stack *stack, int index, t_pushswap_data *ps_data)
{
	while (check_if_last(stack, index))
		mv (RA, ps_data);
}

int	get_last_index(t_stack *stack)
{
	t_stack	*temp;
	int		ret;

	temp = stack;
	ret = -1;
	while (temp)
	{
		ret = temp->index;
		temp = temp->next;
	}
	return (ret);
}

int	move_best_b(t_pushswap_data *ps_data, t_svb svb)
{
	int	rrrotation;

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
	return (1);
}
