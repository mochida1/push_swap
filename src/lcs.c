/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:56:22 by hmochida          #+#    #+#             */
/*   Updated: 2022/08/05 21:11:46 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	lcs_index(t_pushswap_data *ps_data, int **lcs_t, int *unsrt)
{
	int	i;
	int j;

	i = 1;
	j = 1;
	while (i <= ps_data->ele_count)
	{
		while (j <= ps_data->ele_count)
		{
			if (unsrt[i - 1] == ps_data->lut[j - 1])
				lcs_t[i][j] = (lcs_t[i - 1][j - 1]) + 1;
			else if (lcs_t[i - 1][j] >= lcs_t[i][j - 1])
				lcs_t[i][j] = lcs_t[i - 1][j];
			else
				lcs_t[i][j] = lcs_t[i][j - 1];
			j++;
		}
		j = 1;
		i++;
	}
	i = lcs_t[ps_data->ele_count][ps_data->ele_count];
	return (i);
}

int	lcs(int **lcs_t, t_lis *lis, t_pushswap_data *ps_data)
{
	int	index;
	int	i;
	int	j;

	index = lcs_index(ps_data, lcs_t, lis->unsrt);
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
		else if (lcs_t[i - 1][j] > lcs_t[i][j - 1])
			i--;
		else
			j--;
	}
	return (index);
}
