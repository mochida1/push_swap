/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:37:02 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/18 14:38:44 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

void	freedom(t_pushswap_data *ps_data)
{
	free_list(ps_data);
	free (ps_data->lut);
	free (ps_data);
}
