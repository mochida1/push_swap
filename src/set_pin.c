/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:50:52 by hmochida          #+#    #+#             */
/*   Updated: 2022/08/02 21:24:27 by hmochida         ###   ########.fr       */
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
	int	i;

	i = 0;
	lis->unsrt = malloc (sizeof(int) * ps_data->ele_count * 2);
	lis->lcs_t = malloc (sizeof(int *) * (ps_data->ele_count * 2) + 1);
	while (i <= ps_data->ele_count * 2)
		lis->lcs_t[i++] = malloc (sizeof(int) * ps_data->ele_count + 1);
	i = 0;
	while (i <= ps_data->ele_count * 2)
		lis->lcs_t[i++][0] = 0;
	i = 0;
	while (i <= ps_data->ele_count)
		lis->lcs_t[0][i++] = 0;

	// int j = 0;
	// while (j <= ps_data->ele_count * 2)
	// {
	// 	while (i <= ps_data->ele_count)
	// 	{
	// 		lis->lcs_t[j][i] = 0;
	// 		printf ("%d ", lis->lcs_t[j][i++]);
	// 	}
	// 	i = 0;
	// 	printf ("\n");
	// 	j++;
	// }
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
	printf ("setpin P: %p\n", lis->lcs_t);
	lis->lcs_size = lcs(lis->lcs_t, lis->unsrt, ps_data, lis->lcs_m);

	printf ("%d\n", lis->unsrt[0]);
	int i = 0;
	printf ("LIS/PIN: ");
	while (i < lis->lcs_size)
		printf("%d ", lis->lcs_m[i++]);
	printf("\n");

}
