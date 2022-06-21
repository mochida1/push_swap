/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:19:52 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/20 21:16:02 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

/*
** Frees the STACK A list. Not B. Only A
*/
void	free_list(t_pushswap_data *ps_data)
{
	t_stack *temp;

	temp = ps_data->head_a;
	while (ps_data->head_a)
	{
		temp = ps_data->head_a;
		ps_data->head_a = ps_data->head_a->next;
		free (temp);
		temp = NULL;
	}
}
