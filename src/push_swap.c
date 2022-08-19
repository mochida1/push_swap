/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:32:17 by hmochida          #+#    #+#             */
/*   Updated: 2022/08/19 23:27:34 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
** A really hard to understand function.
*/
int	push_swap(t_pushswap_data *ps_data)
{
	if (ps_data->ele_count == 2)
		sort_two(ps_data);
	else if (ps_data->ele_count == 3)
		sort_three(ps_data);
	else if (ps_data->ele_count >= 4 && ps_data->ele_count < 50)
		sort_vb(ps_data);
	else
		sort_radix(ps_data);
	print_mv(ps_data->mv_to_print);
	return (0);
}

/*
** This is what calls __start and all that good shit.
*/
int	main(int argc, char *argv[])
{
	t_pushswap_data	*ps_data;
	int				in_nbr;

	in_nbr = validate_inputs(argc, argv);
	ps_data = malloc(sizeof(t_pushswap_data));
	init_data (ps_data, in_nbr, argv);
	check_repeated_numbers(ps_data);
	sort_lut(ps_data);
	push_swap(ps_data);
	freedom(ps_data);
	return (0);
}
