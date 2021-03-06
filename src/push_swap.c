/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:32:17 by hmochida          #+#    #+#             */
/*   Updated: 2022/07/31 03:19:25 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
**
*/
int	push_swap(t_pushswap_data *ps_data) //heisenbug: 3 2 1 faz desaparecer um indice.
{
	if (ps_data->ele_count == 2)
		sort_two(ps_data);
	if (ps_data->ele_count == 3)
		sort_three(ps_data);
	if (ps_data->ele_count >= 4)
		set_pin(ps_data);
		// sort_me(ps_data);


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

	print_mv(ps_data->mv_to_print);
	printf("----------A----------\n");
	print_list(ps_data->head_a);
	printf("END_A:%p \n", ps_data->end_a);
	printf("----------B----------\n");
	print_list(ps_data->head_b);
	printf("END_B:%p \n", ps_data->end_b);
	freedom(ps_data);
	return (0);
}
