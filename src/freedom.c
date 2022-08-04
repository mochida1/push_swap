/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:37:02 by hmochida          #+#    #+#             */
/*   Updated: 2022/08/04 20:32:00 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
** FREEEEEEEDDOOOOOOOOOOMMMM!!! Now I can exit the program without leaks.
*/
void	freedom(t_pushswap_data *ps_data)
{
	free_moves_array(ps_data->moves);
	free_print_list(ps_data->mv_to_print);
	if (ps_data->pin_head)
		free_pin(ps_data->pin_head);
	free_list(ps_data);
	free (ps_data->lut);
	free (ps_data);
}
