/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:37:36 by hmochida          #+#    #+#             */
/*   Updated: 2022/08/04 19:16:46 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int is_pin(int check_num, t_pin *pin_head)
{
	t_pin *temp;

	temp = pin_head;
	while (temp)
	{
		if (check_num == temp->num)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	case_1(t_pushswap_data *ps_data)
{
	printf ("\nIS_PIN: %d <<<<<\n", is_pin(ps_data->head_a->num, ps_data->pin_head));
	// if (ps_data->head_a && ps_data->head_b)
	// 	return (0);
	// if (is_pin(ps_data->head_a->num, ps_data->pin_head))
	// 	&& is_pin(ps_data->head_b->num, ps_data->pin_head))
	// {

	// }
	return 0;
}

/*
** sort case for more than three elements;
*/
void	sort_me(t_pushswap_data *ps_data)
{
	set_pin(ps_data);
	if (case_1(ps_data))
	return ;
}
