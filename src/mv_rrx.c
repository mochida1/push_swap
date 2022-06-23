/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:01:39 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/23 19:11:55 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static t_stack	*get_last_adress(t_stack *stack_x)
{
	t_stack	*temp;

	temp = stack_x;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	mv_rra(t_pushswap_data *ps_data, int log_mv)
{
	t_stack	*temp;
	t_stack	*tp;

	if (ps_data->head_a && ps_data->head_a->next)
	{
		temp = ps_data->head_a;
		tp = get_last_adress(ps_data->head_a);
		tp->prev->next = NULL;
		temp->prev = tp;
		ps_data->head_a = tp;
		tp->next = temp;
		tp->prev = NULL;
	}
	if (log_mv)
		add_to_mv(RRA, ps_data);
}

void	mv_rrb(t_pushswap_data *ps_data, int log_mv)
{
	t_stack	*temp;
	t_stack	*tp;

	if (ps_data->head_b && ps_data->head_b->next)
	{
		temp = ps_data->head_b;
		tp = get_last_adress(ps_data->head_b);
		tp->prev->next = NULL;
		temp->prev = tp;
		ps_data->head_b = tp;
		ps_data->head_b->next = temp;
		ps_data->head_b->prev = NULL;
	}
	if (log_mv)
		add_to_mv(RRB, ps_data);
}

void	mv_rrr(t_pushswap_data *ps_data)
{
	mv_rra(ps_data, 0);
	mv_rrb(ps_data, 0);
	add_to_mv(RRR, ps_data);
}
