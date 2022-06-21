/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_wrapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:18:11 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 17:10:58 by hmochida         ###   ########.fr       */
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
