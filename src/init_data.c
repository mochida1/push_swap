/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:52:16 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 15:05:43 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

/*
** Allocates and initializes most of the data used in the program,
** with exception of *ps_data.
*/
void	init_data(t_pushswap_data *ps_data, int in_nbr, char *argv[])
{
	ps_data->ele_count = in_nbr;
	ps_data->pin = malloc (sizeof(int) * ps_data->ele_count);
	get_lut(ps_data, argv);
	create_stack(ps_data);
	create_moves_array(ps_data);
}
