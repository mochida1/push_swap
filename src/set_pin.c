/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:50:52 by hmochida          #+#    #+#             */
/*   Updated: 2022/07/31 08:48:42 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	fill_unsorted(int *unsrt, t_pushswap_data *ps_data)
{
	int	i;
	int	flag;
	t_stack *temp;

	temp = ps_data->head_a;
	i = 0;
	flag = 0;
	while (temp)
	{
		unsrt[i] = temp->num;
		temp = temp->next;
		i++;
		if (!flag && !temp)
		{
			flag = 1;
			temp = ps_data->head_a;
		}
	}
}

static void	init_mats(t_lis *lis, t_pushswap_data *ps_data)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	lis->unsrt = malloc (sizeof(int) * ps_data->ele_count * 2);
	lis->lcs_tab = malloc (sizeof(int *) * ps_data->ele_count * 2);
	while (i[0] < ps_data->ele_count * 2)
	{
		lis->lcs_tab[i[0]] = malloc (sizeof(int) * ps_data->ele_count);
		i[0]++;
	}
	i[0] = 0;
	while (i[0] < ps_data->ele_count * 2)
	{
		while (i[1] < ps_data->ele_count)
		{
			lis->lcs_tab[i[0]][i[1]] = 0;
			i[1]++;
		}
		i[0]++;
		i[1] = 0;
	}
	fill_unsorted(lis->unsrt, ps_data);
}

/*
** sets ps_data->pin to the longest incresing sequence numbers from
** arguments.
*/
void	set_pin(t_pushswap_data *ps_data)
{
	t_lis *lis;

	lis = malloc (sizeof (t_lis));
	init_mats(lis, ps_data);
	printf ("setpin P: %p\n", lis->lcs_tab);
	lis->lcs_size = lcs(lis->lcs_tab, lis->unsrt, ps_data, lis->lcs_m);

	printf ("%d\n", lis->unsrt[0]);
	int i = 0;
	while (i < lis->lcs_size)
		printf("%d ", lis->lcs_m[i++]);
	printf("\n");

}
