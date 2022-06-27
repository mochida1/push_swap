/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:50:52 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/27 19:53:24 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_pin	*get_pin(t_pushswap_data *ps_data, int i)
{
	int		k;
	int		t_num;
	t_stack	*temp;
	t_pin	*ret;

	temp = ps_data->head_a;
	t_num = 0;
	k = 0;
	while (i--)
		temp = temp->next;
	
	return (ret);
}

/*
** sets ps_data->pin to the largest sequence of already sorted numbers in the
** arguments.
*/
void	set_pin(t_pushswap_data *ps_data)
{
	int		i;
	int		temp_sz;
	t_pin	*temp;

	i = 0;
	while (i < ps_data->ele_count)
	{
		temp = get_pin(ps_data, i);
		temp_sz = count_pin_list(temp);
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
