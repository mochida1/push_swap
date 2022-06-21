/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:56:38 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 15:13:36 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

/*
** makes the swap movent on the A list and saves it to mv_to_print.
*/
void	mv_swap_stack_a(t_pushswap_data *ps_data)
{
	t_stack	*temp;

	if (ps_data->head_a->next)
	{
		temp = ps_data->head_a;
		ps_data->head_a->next = ps_data->head_a;
		ps_data->head_a = temp;
	}
	add_to_mv(SWAP_A, ps_data);
}

/*
** makes the swap movent on the B list and saves it to mv_to_print.
*/
void	mv_swap_stack_b(t_pushswap_data *ps_data)
{
	t_stack	*temp;

	if (ps_data->head_b->next)
	{
		temp = ps_data->head_b;
		ps_data->head_b->next = ps_data->head_b;
		ps_data->head_b = temp;
	}
	add_to_mv(SWAP_B, ps_data);
}

/*
** makes the swap movent on both lists and saves it to mv_to_print.
*/
void	mv_swap_stack_s(t_pushswap_data *ps_data)
{
	mv_swap_stack_a(ps_data);
	mv_swap_stack_b(ps_data);
	add_to_mv(SWAP_S, ps_data);
}
