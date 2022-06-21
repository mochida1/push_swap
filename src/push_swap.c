/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:32:17 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 16:34:12 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

/*
**
*/
t_movements	*push_swap(t_pushswap_data *ps_data)
{
	if (ps_data->ele_count == 2)
		sort_two(ps_data);
	return (0);
}

/*
** This is what calls __start and all that good shit.
*/
int	main (int argc, char *argv[])
{
	t_pushswap_data *ps_data;
	int in_nbr;

	in_nbr = validate_inputs(argc, argv);
	ps_data = malloc(sizeof(t_pushswap_data));
	init_data (ps_data, in_nbr, argv);
	check_repeated_numbers(ps_data);
	sort_lut(ps_data);
	push_swap(ps_data);

	//print_list(ps_data);
	print_mv(ps_data);
	freedom(ps_data);
	return (0);
}
