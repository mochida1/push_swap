/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_wrapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:18:11 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/20 21:24:18 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

void	mv(char *mv, t_pushswap_data *ps_data, t_movements *mv_to_print)
{
	if (mv == SWAP_A)
		mv_swap_stack_a(ps_data, mv_to_print);
	else if (mv == SWAP_B)
		mv_swap_stack_b(ps_data, mv_to_print);
	else if (mv == SWAP_S)
		mv_swap_stack_s(ps_data, mv_to_print);
	else if (mv == RA)
		return ;
	else if (mv == RB)
		return ;
	else if (mv == RR)
		return ;
	else if (mv == RRA)
		return ;
	else if (mv == RRB)
		return ;
	else if (mv == RRR)
		return ;
	else if (mv == PB)
		return ;
	else if (mv == PA)
		return ;
}