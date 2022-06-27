/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:50:52 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/27 14:47:01 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	set_pin(t_pushswap_data *ps_data)
{
	int		i;
	int		temp_sz;
	t_pin	*temp;

	i = 0;
	while (i < ps_data->ele_count)
	{
		temp = get_pin(ps_data, i);
		temp_sz = count_list(temp);
		if (temp_sz >= ps_data->pin_size && ps_data->pin != temp)
		{
			ps_data->pin = temp;
			ps_data->pin_size = temp_sz;
			free_pin(ps_data->pin);
		}
		else
		{
			free_pin(temp);
			temp = NULL;
		}
		i++;
	}
}
