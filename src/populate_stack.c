/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:01:41 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/18 15:30:10 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

/*
** Fills up STACK A with relevant data.
*/
int	populate_stack(t_pushswap_data *ps_data)
{
	t_stack	*temp;
	int	i;

	temp = ps_data->head_a;
	i = 0;
	while (i < ps_data->ele_count)
	{
		temp->num = ps_data->lut[i];
		temp->is_indexed = 0;
		temp->stack_order = i;
		temp = temp->next;
		i++;
	}
	temp = NULL;
	ps_data->end_a = temp;
	return (0);
}
