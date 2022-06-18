/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:37:02 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/18 19:50:21 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

/*
** FREEEEEEEDDOOOOOOOOOOMMMM!!! Now I can exit the program without leaks.
*/
void	freedom(t_pushswap_data *ps_data)
{
	free_list(ps_data);
	free (ps_data->lut);
	free (ps_data->pin);
	free (ps_data);
}
