/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_mv_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:21:33 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/20 19:21:48 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

void	add_to_mv(char *move, t_movements *mv_to_print)
{
	t_movements *temp;

	if (mv_to_print == NULL)
	{
		mv_to_print = malloc (sizeof(t_movements));
		mv_to_print->movement = move;
	}
	else
	{
		temp = mv_to_print;
		while (temp->next)
		{
			temp = temp->next;
		}
		
		
	}
		
}