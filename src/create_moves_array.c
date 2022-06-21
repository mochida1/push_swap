/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_moves_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:56:32 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 17:10:58 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	create_moves_array(t_pushswap_data *ps_data)
{
	ps_data->moves = malloc (sizeof(char *) * 12);
	ps_data->moves[SA] = ft_strdup("sa\n");
	ps_data->moves[SB] = ft_strdup("sb\n");
	ps_data->moves[SS] = ft_strdup("ss\n");
	ps_data->moves[RA] = ft_strdup("ra\n");
	ps_data->moves[RB] = ft_strdup("rb\n");
	ps_data->moves[RR] = ft_strdup("rr\n");
	ps_data->moves[RRA] = ft_strdup("rra\n");
	ps_data->moves[RRB] = ft_strdup("rrb\n");
	ps_data->moves[RRR] = ft_strdup("rrr\n");
	ps_data->moves[PB] = ft_strdup("pb\n");
	ps_data->moves[PA] = ft_strdup("pa\n");
	ps_data->moves[11] = NULL;
}
