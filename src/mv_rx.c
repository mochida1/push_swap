/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:59:36 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 17:29:01 by hmochida         ###   ########.fr       */
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

void	mv_ra(t_pushswap_data *ps_data, int log_mv)
{
	t_stack	*temp;
	t_stack	*tp;

	if (ps_data->head_a && ps_data->head_a->next)
	{
		temp = ps_data->head_a;
		tp = get_last_adress(ps_data->head_a);
		ps_data->head_a = ps_data->head_a->next;
		ps_data->head_a->prev = NULL;
		tp->next = temp;
		temp->prev = tp;
		temp->next = NULL;
	}
	if (log_mv)
		add_to_mv(RA, ps_data);
}

void	mv_rb(t_pushswap_data *ps_data, int log_mv)
{
	t_stack	*temp;
	t_stack	*tp;

	if (ps_data->head_b && ps_data->head_b->next)
	{
		temp = ps_data->head_b;
		tp = get_last_adress(ps_data->head_b);
		ps_data->head_b = ps_data->head_b->next;
		ps_data->head_b->prev = NULL;
		tp->next = temp;
		temp->prev = tp;
		temp->next = NULL;
	}
	if (log_mv)
		add_to_mv(RB, ps_data);
}

void	mv_rr(t_pushswap_data *ps_data)
{
	mv_ra(ps_data, 0);
	mv_ra(ps_data, 0);
	add_to_mv(RR, ps_data);
}
