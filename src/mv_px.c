/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:01:36 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 20:31:29 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	mv_pb(t_pushswap_data *ps_data)
{
	t_stack *temp;
	t_stack *tn;

	temp = ps_data->head_a;
	if (temp)
	{
		ps_data->head_a = ps_data->head_a->next;
		ps_data->head_a->prev = NULL;
	}
	if (!ps_data->head_b)
	{
		ps_data->head_b = temp;
		ps_data->head_b->next = NULL;
		ps_data->head_b->prev = NULL;
	}
	else
	{
		tn = ps_data->head_b;
		tn->prev = temp;
		ps_data->head_b = temp;
		temp->next = tn;
	}
	add_to_mv(PB, ps_data);
}

void	mv_pa(t_pushswap_data *ps_data)
{
	t_stack *temp;
	t_stack *tn;

	temp = ps_data->head_b;
	if (temp)
	{
		ps_data->head_b = ps_data->head_b->next;
		ps_data->head_b->prev = NULL;
	}
	if (!ps_data->head_a)
	{
		ps_data->head_a = temp;
		ps_data->head_a->next = NULL;
		ps_data->head_a->prev = NULL;
	}
	else
	{
		tn = ps_data->head_a;
		tn->prev = temp;
		ps_data->head_a = temp;
		temp->next = tn;
	}
	add_to_mv(PA, ps_data);
}
