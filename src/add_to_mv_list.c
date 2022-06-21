/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_mv_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:21:33 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 16:55:19 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	add_to_mv(int move, t_pushswap_data *ps_data)
{
	t_movements	*temp;

	if (ps_data->mv_to_print == NULL)
	{
		ps_data->mv_to_print = malloc (sizeof(t_movements));
		ps_data->mv_to_print->movement = ps_data->moves[move];
		ps_data->mv_to_print->next = NULL;
	}
	else
	{
		temp = ps_data->mv_to_print;
		ps_data->mv_to_print = malloc (sizeof(t_movements));
		ps_data->mv_to_print->movement = ps_data->moves[move];
		ps_data->mv_to_print->next = temp;
	}
}
