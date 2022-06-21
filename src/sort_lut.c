/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:54:01 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 16:40:29 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
/*
** Swap values inside an array;
*/
static void	swap_elements(t_pushswap_data *ps_data, int i, int hold)
{
	int	temp;

	temp = ps_data->lut[hold];
	ps_data->lut[hold] = ps_data->lut[i];
	ps_data->lut[i] = temp;
}

/*
** Easy and simple selection sort to make up the LUT;
** Yes, a bubble sort would be easier - AND - better. But sometimes you just
** want to use the worst stuff because you can.
*/
void	sort_lut(t_pushswap_data *ps_data)
{
	int	hold;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ps_data->ele_count)
	{
		hold = i;
		while (j < ps_data->ele_count)
		{
			if (ps_data->lut[j] < ps_data->lut[hold])
				hold = j;
			j++;
		}
		swap_elements(ps_data, i, hold);
		i++;
		j = i + 1;
	}
}
