/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:36:00 by coder             #+#    #+#             */
/*   Updated: 2022/08/19 23:31:06 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	sort_radix(t_pushswap_data *ps_data)
{
	int	i;
	int	loop_count;
	int	last_index;

	index_to_data(ps_data);
	last_index = get_largest_index(ps_data);
	i = 0;
	loop_count = msb(last_index);
	while (i <= loop_count)
	{
		move_zero(ps_data, i);
		while (ps_data->head_b)
			mv(PA, ps_data);
		i++;
	}
	return (1);
}
