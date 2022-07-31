/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:50:52 by hmochida          #+#    #+#             */
/*   Updated: 2022/07/31 01:33:48 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	init_mats(int **lcs_tab, int *unsorted, t_pushswap_data *ps_data)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	unsorted = malloc (sizeof(int) * ps_data->ele_count * 2);
	lcs_tab = malloc (sizeof(int *) * ps_data->ele_count * 2);
	while (i[0] < ps_data->ele_count * 2)
	{
		lcs_tab[i[0]] = malloc (sizeof(int) * ps_data->ele_count);
		i[0]++;
	}
	i[0] = 0;
	while (i[0] < ps_data->ele_count * 2)
	{
		while (i[1] < ps_data->ele_count)
		{
			lcs_tab[i[0]][i[1]] = 0;
			i[1]++;
		}
		i[0]++;
		i[1] = 0;
	}
	fill_unsorted(unsorted, ps_data);
}

/*
** sets ps_data->pin to the longest incresing sequence numbers from
** arguments.
*/
void	set_pin(t_pushswap_data *ps_data)
{
	int	**lcs_tab; // 2len x len
	int	*unsrt;
	int	*lcs_m;
	int	lcs_size;

	init_mats(lcs_tab, unsrt, ps_data);
	lcs_size = lcs(lcs_tab, unsrt, ps_data, lcs_m);

}
