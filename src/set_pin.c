/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:50:52 by hmochida          #+#    #+#             */
/*   Updated: 2022/08/03 21:55:27 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	fill_unsorted(int *unsrt, t_pushswap_data *ps_data)
{
	int	i;
	t_stack *temp;

	temp = ps_data->head_a;
	i = 0;
	while (temp)
	{
		unsrt[i] = temp->num;
		temp = temp->next;
		i++;
	}
}

static void	init_mats(t_lis *lis, t_pushswap_data *ps_data)
{
	int	i;

	i = 0;
	lis->unsrt = malloc (sizeof(int) * ps_data->ele_count);
	lis->lcs_t = malloc (sizeof(int *) * (ps_data->ele_count) + 1);
	while (i <= ps_data->ele_count * 2)
		lis->lcs_t[i++] = malloc (sizeof(int) * ps_data->ele_count + 1);
	i = 0;
	while (i <= ps_data->ele_count * 2)
		lis->lcs_t[i++][0] = 0;
	i = 0;
	while (i <= ps_data->ele_count)
		lis->lcs_t[0][i++] = 0;
	fill_unsorted(lis->unsrt, ps_data);
}

static void	free_lcs_lists(t_lis *lis, t_pushswap_data *ps_data)
{
	int	i;

	i = 0;
	free (lis->unsrt);
	while (i <= ps_data->ele_count)
		free(lis->lcs_t[i++]);
	free(lis->lcs_m);
	lis->lcs_size = 0;
	free(lis);
}

static void	remake_pin(t_lis *lis, t_pushswap_data *ps_data)
{

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
	lis->lcs_size = lcs(lis->lcs_t, lis->unsrt, ps_data, lis->lcs_m);
	if (ps_data->pin_head)
	remake_pin(lis, ps_data);
	free_lcs_lists(lis, ps_data);
}
