/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:56:38 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/20 17:25:04 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

/*
** make the swap b movent on the list and saves it to mv_to_print.
*/
void	swap_stack_b(t_pushswap_data *ps_data, t_movements *mv_to_print)
{
	t_stack	*temp;
	
	if (ps_data->head_b->next)
	{
		ps_data->head_b = temp;
		ps_data->head_b->next = ps_data->head_b;
		ps_data->head_b = temp;
	}
	add_to_mv(SWAP_B, mv_to_print);
}

/*
** make the swap a movent on the list and saves it to mv_to_print.
*/
void	swap_stack_a(t_pushswap_data *ps_data, t_movements *mv_to_print)
{
	t_stack	*temp;
	
	if (ps_data->head_a->next)
	{
		ps_data->head_a = temp;
		ps_data->head_a->next = ps_data->head_a;
		ps_data->head_a = temp;
	}
	add_to_mv(SWAP_A, mv_to_print);
}