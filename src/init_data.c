/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:52:16 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/17 20:48:36 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

void	init_data(t_pushswap_data *ps_data, int in_nbr, char *argv[])
{
	ps_data->ele_count = in_nbr;
	get_lut(ps_data, argv);
}
