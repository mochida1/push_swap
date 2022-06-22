/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:19:38 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/22 20:32:31 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	comp_num_lut(int num, int *lut, int ele_count)
{
	int i;

	i = 0;
	while (i < ele_count)
	{
		if (num == lut[i])
			return(i);
		i++;
	}
	return (-1);
}

void	get_stack_index(t_pushswap_data *ps_data)
{
	t_stack *temp;

	temp = ps_data->head_a;
	while (temp)
	{
		temp->index = comp_num_lut(temp->num, ps_data->lut, ps_data->ele_count);
		temp = temp->next;
	}
}