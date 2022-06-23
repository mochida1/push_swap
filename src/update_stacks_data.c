/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stacks_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:37:54 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/23 19:41:25 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	update_stacks_order(t_pushswap_data *ps_data)
{
	t_stack	*temp;
	int		i;

	if (ps_data->head_a)
	{
		i = 0;
		temp = ps_data->head_a;
		while (temp)
		{
			temp->stack_order = i++;
			ps_data->end_a = temp;
			temp = temp->next;
		}
	}
	if (ps_data->head_b)
	{
		i = 0;
		temp = ps_data->head_b;
		while (temp)
		{
			temp->stack_order = i++;
			ps_data->end_b = temp;
			temp = temp->next;
		}
	}
}

void	update_stacks_data(t_pushswap_data *ps_data)
{
	update_stacks_order(ps_data);
}
