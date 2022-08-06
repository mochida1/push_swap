/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:19:42 by hmochida          #+#    #+#             */
/*   Updated: 2022/08/04 20:31:36 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
** Frees ps_data->pin list
*/
void	free_pin(t_pushswap_data *ps_data)
{
	t_pin	*tempin;

	while (ps_data->pin_head)
	{
		tempin = ps_data->pin_head;
		ps_data->pin_head = ps_data->pin_head->next;
		free (tempin);
	}
}
