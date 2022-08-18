/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_vb_utils04.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:09:59 by coder             #+#    #+#             */
/*   Updated: 2022/08/19 01:13:42 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	move_best_a(t_pushswap_data *ps_data, t_svb svb)
{
	int	rrrotation;
	int	should_be_on_bot;

	if (!svb.best_a && (svb.index_a > svb.index_b))
		return (0);
	rrrotation = 0;
	should_be_on_bot = 0;
	if (svb.index_a < svb.index_b)
		should_be_on_bot = 1;
	if (svb.best_a < ((svb.size_a + should_be_on_bot) / 2))
		rrrotation = 1;
	if (!should_be_on_bot && !rrrotation)
		while (ps_data->head_a->index != svb.index_a)
			mv (RA, ps_data);
	else if (!should_be_on_bot && rrrotation)
		while (ps_data->head_a->index != svb.index_a)
			mv (RRA, ps_data);
	else if (should_be_on_bot && !rrrotation)
		rr_till_bot(ps_data->head_a, svb.index_a, ps_data);
	else if (should_be_on_bot && rrrotation)
		rrrr_till_bot(ps_data->head_a, svb.index_a, ps_data);
	return (1);
}

t_svb	init_svb(t_pushswap_data *ps_data)
{
	t_svb	ret;

	ret.size_a = get_stack_size(ps_data->head_a);
	ret.size_b = get_stack_size(ps_data->head_b);
	ret.best_b = get_best_to_mv(ps_data, ret);
	ret.best_a = get_best_a(ps_data, ret);
	ret.dist_a = calc_moves_quant(ret.best_a, ret.size_a);
	ret.dist_b = calc_moves_quant(ret.best_b, ret.size_b);
	ret.index_a = get_lut_from (ret.best_a, ps_data->head_a);
	ret.index_b = get_lut_from (ret.best_b, ps_data->head_b);
	return (ret);
}

int	i_should_rrr(t_pushswap_data *ps_data)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = ps_data->head_a;
	while (temp->index)
	{
		temp = temp->next;
		i++;
	}
	if (i < ((ps_data->ele_count - 1) / 2))
		return (0);
	return (1);
}
