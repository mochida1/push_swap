/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:19:42 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/30 11:25:30 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
** Frees ps_data->pin list
*/
void	free_pin(t_pin *pin)
{
	t_pin	*tempin;

	while (pin)
	{
		tempin = pin;
		pin = pin->next;
		free (tempin);
	}
}