/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:28:47 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 17:10:39 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_two(t_pushswap_data *ps_data)
{
	if (ps_data->head_a->num != ps_data->lut[0])
		mv(SA, ps_data, ps_data->mv_to_print);
}
