/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_moves_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:03:27 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 15:18:32 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

void	free_moves_array(char **moves)
{
	char **temp;

	temp = moves;
	while (*moves)
	{
		free(*moves);
		moves++;
	}
	free (temp);
}
