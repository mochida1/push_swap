/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:39:53 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 16:43:26 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
** Prints the stack of moves made.
*/
void	print_mv(t_pushswap_data *ps_data)
{
	t_movements	*temp;

	temp = ps_data->mv_to_print;
	while (temp)
	{
		ft_putstr_fd(temp->movement, 1);
		temp = temp->next;
	}
}
