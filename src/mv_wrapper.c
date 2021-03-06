/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_wrapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:18:11 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/22 10:39:35 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	mv(int mv, t_pushswap_data *ps_data)
{
	if (mv == SA)
		mv_sa(ps_data, 1);
	else if (mv == SB)
		mv_sb(ps_data, 1);
	else if (mv == SS)
		mv_ss(ps_data);
	else if (mv == RA)
		mv_ra(ps_data, 1);
	else if (mv == RB)
		mv_rb(ps_data, 1);
	else if (mv == RR)
		mv_rr(ps_data);
	else if (mv == RRA)
		mv_rra(ps_data, 1);
	else if (mv == RRB)
		mv_rrb(ps_data, 1);
	else if (mv == RRR)
		mv_rrr(ps_data);
	else if (mv == PB)
		mv_pb(ps_data);
	else if (mv == PA)
		mv_pa(ps_data);
	update_stacks_data(ps_data);
}
