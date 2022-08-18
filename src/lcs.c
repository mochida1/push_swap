/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:56:22 by hmochida          #+#    #+#             */
/*   Updated: 2022/08/19 01:15:00 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	lcs_index(t_pushswap_data *ps_data, t_lis *lis)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= ps_data->ele_count)
	{
		while (j <= ps_data->ele_count)
		{
			if (lis->unsrt[i - 1] == ps_data->lut[j - 1])
				lis->lcs_t[i][j] = (lis->lcs_t[i - 1][j - 1]) + 1;
			else if (lis->lcs_t[i - 1][j] >= lis->lcs_t[i][j - 1])
				lis->lcs_t[i][j] = lis->lcs_t[i - 1][j];
			else
				lis->lcs_t[i][j] = lis->lcs_t[i][j - 1];
			j++;
		}
		j = 1;
		i++;
	}
	i = lis->lcs_t[ps_data->ele_count][ps_data->ele_count];
	return (i);
}

/*
** fills the lis struct with relevant data, returns the number of elements in
** lis->lcs_m, wich is our largest increasing sequence :)
*/
int	lcs(t_lis *lis, t_pushswap_data *ps_data)
{
	int	index;
	int	i;
	int	j;
	int	ret;

	index = lcs_index(ps_data, lis);
	ret = index;
	lis->lcs_m = malloc(sizeof(int) * index);
	i = ps_data->ele_count;
	j = ps_data->ele_count;
	while (i > 0 && j > 0)
	{
		if (lis->unsrt[i - 1] == ps_data->lut[j - 1])
		{
			lis->lcs_m[index - 1] = lis->unsrt[i - 1];
			i--;
			j--;
			index--;
		}
		else if (lis->lcs_t[i - 1][j] > lis->lcs_t[i][j - 1])
			i--;
		else
			j--;
	}
	return (ret);
}
