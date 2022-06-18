/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:54:01 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/18 20:42:51 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

static void	swap_elements(t_pushswap_data *ps_data, int i, int hold)
{
	int temp;
	temp = ps_data->lut[hold];
	if (ps_data->lut[i] > ps_data->lut[hold])
	{
		ps_data->lut[i] = ps_data->lut[hold];
		ps_data->lut[hold] = temp;
	}
}

void	sort_lut(t_pushswap_data *ps_data)
{
	int hold;
	int i;
	int j;

	i = 0;
	j = 1;
	printf ("ELES:%d\n", ps_data->ele_count);
	fflush(stdout);
	while (i < ps_data->ele_count)
	{
		hold = ps_data->lut[i];
		while (j < ps_data->ele_count)
		{
			if (ps_data->lut[j] < hold)
				hold = j;
			j++;
		}
		swap_elements(ps_data, i, hold);
		i++;
		j = i + 1;
	}

	// daqui pra baixo é teste
	i = 0;
	while (i < ps_data->ele_count)
	{
		printf("%d:%d\n", i, ps_data->lut[i]);
		i++;
	}
	//
}
