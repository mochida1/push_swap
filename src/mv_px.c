/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:01:36 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/22 10:25:54 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// static t_stack	*get_last_adress(t_stack *stack_x)
// {
// 	t_stack	*temp;

// 	temp = stack_x;
// 	while (temp->next)
// 		temp = temp->next;
// 	return (temp);
// }

void	mv_pb(t_pushswap_data *ps_data)
{
	t_stack	*temp;
	t_stack	*tn;

	temp = ps_data->head_a;
	tn = ps_data->head_b;
	if (temp)
	{
		ps_data->head_a = ps_data->head_a->next;
		if (ps_data->head_a)
			ps_data->head_a->prev = NULL;
		if (!ps_data->head_b)
		{
			ps_data->head_b = temp;
			ps_data->head_b->next = NULL;
			ps_data->head_b->prev = NULL;
		}
		else
		{
			ps_data->head_b = temp;
			ps_data->head_b->prev = NULL;
			ps_data->head_b->next = tn;
			tn->prev = temp;
		}
	}
	add_to_mv(PB, ps_data);
}

void	mv_pa(t_pushswap_data *ps_data)
{
	t_stack	*temp;
	t_stack	*tn;

	temp = ps_data->head_b;
	tn = ps_data->head_a;
	if (temp)
	{
		ps_data->head_b = ps_data->head_b->next;
		if (ps_data->head_b)
			ps_data->head_b->prev = NULL;
		if (!ps_data->head_a)
		{
			ps_data->head_a = temp;
			ps_data->head_a->next = NULL;
			ps_data->head_a->prev = NULL;
		}
		else
		{
			ps_data->head_a = temp;
			ps_data->head_a->prev = NULL;
			ps_data->head_a->next = tn;
			tn->prev = temp;
		}
	}
	add_to_mv(PA, ps_data);
}
