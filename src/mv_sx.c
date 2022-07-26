/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:56:38 by hmochida          #+#    #+#             */
/*   Updated: 2022/07/26 19:26:23 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
** makes the swap movent on the A list and saves it to mv_to_print.
*/
void	mv_sa(t_pushswap_data *ps_data, int log_mv)
{
	t_stack	*temp;
	t_stack	*tn;
	t_stack	*tnn;

	if (ps_data->head_a && ps_data->head_a->next)
	{
		temp = ps_data->head_a;
		tn = ps_data->head_a->next;
		if (ps_data->head_a->next->next)
			tnn = temp->next->next;
		else
			tnn = NULL;
		ps_data->head_a = ps_data->head_a->next;
		ps_data->head_a->prev = NULL;
		ps_data->head_a->next = temp;
		temp->prev = tn;
		temp->next = tnn;
		tnn->prev = temp;
	}
	if (log_mv)
		add_to_mv(SA, ps_data);
}

/*
** makes the swap movent on the B list and saves it to mv_to_print.
*/
void	mv_sb(t_pushswap_data *ps_data, int log_mv)
{
	t_stack	*temp;
	t_stack	*tn;
	t_stack	*tnn;

	if (ps_data->head_b && ps_data->head_b->next)
	{
		temp = ps_data->head_b;
		tn = ps_data->head_b->next;
		tnn = temp->next->next;
		ps_data->head_b = ps_data->head_b->next;
		ps_data->head_b->prev = NULL;
		ps_data->head_b->next = temp;
		temp->prev = tn;
		temp->next = tnn;
		tnn->prev = temp;
	}
	if (log_mv)
		add_to_mv(SB, ps_data);
}

/*
** makes the swap movent on both lists and saves it to mv_to_print.
*/
void	mv_ss(t_pushswap_data *ps_data)
{
	mv_sa(ps_data, 0);
	mv_sb(ps_data, 0);
	add_to_mv(SS, ps_data);
}
