/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:56:22 by hmochida          #+#    #+#             */
/*   Updated: 2022/07/31 02:40:06 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	lcs_index(t_pushswap_data *ps_data, int **lcs_t, int *unsrt)
{
	int	i;
	int j;

	i = 1;
	j = 1;
	while (i <= ps_data->ele_count * 2)
	{
		while (j <= ps_data->ele_count)
		{
			if (unsrt[i - 1] == ps_data->lut[j - 1])
				lcs_t[i][j] = lcs_t[i - 1][j - 1] + 1;
			else if (lcs_t[i - 1][j] >= lcs_t[i][j - 1])
				lcs_t[i][j] = lcs_t[i - 1][j];
			else
				lcs_t[i][j] = lcs_t[i][j - 1];
			j++;
		}
		j = 0;
		i++;
	}
	return (lcs_t[ps_data->ele_count * 2][ps_data->ele_count]);
}

int	lcs(int **lcs_t, int *unsrt, t_pushswap_data *ps_data, int *lcs_m)
{
	int	index;
	int	i;
	int	j;

	index = lcs_index(ps_data, lcs_t, unsrt);
	lcs_m = malloc(sizeof(int) * index);
	i = ps_data->ele_count * 2;
	j = ps_data->ele_count;
	while (i > 0 && j > 0)
	{
		if (unsrt[i - 1] == ps_data->lut[j - 1])
		{
			lcs_m[index - 1] = unsrt[i - 1];
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
