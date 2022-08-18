/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_vb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:30:48 by coder             #+#    #+#             */
/*   Updated: 2022/08/19 01:13:07 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	case03(t_pushswap_data *ps_data)
{
	if (i_should_rrr(ps_data))
		while (ps_data->head_a->index)
			mv(RRA, ps_data);
	else
		while (ps_data->head_a->index)
			mv(RA, ps_data);
	return (1);
}

int	case02(t_pushswap_data *ps_data)
{
	t_svb	svb;

	while (ps_data->head_b)
	{
		svb = init_svb(ps_data);
		move_best_a (ps_data, svb);
		move_best_b (ps_data, svb);
	}
	return (1);
}

int	case01(t_pushswap_data *ps_data)
{
	t_stack	*temp;

	temp = ps_data->head_a;
	if (temp->next && ((temp->is_indexed && !temp->next->is_indexed)
			|| (temp->next->is_indexed && !temp->is_indexed)))
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

void	sort_vb(t_pushswap_data *ps_data)
{
	set_pin(ps_data);
	pin_to_data(ps_data);
	index_to_data(ps_data);
	while (!stack_is_indexed(ps_data->head_a))
		case01(ps_data);
	case02(ps_data);
	case03(ps_data);
}
