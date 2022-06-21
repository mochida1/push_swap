/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_print_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:05:29 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/20 21:07:42 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

void	free_print_list(t_movements *list)
{
	t_movements *temp;

	while (list->next)
	{
		temp = list;
		list = list->next;
		free(temp);
		temp = NULL;
	}
}