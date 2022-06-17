/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:32:17 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/17 19:54:05 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"
//char	**push_swap;

int	main (int argc, char *argv[])
{
	t_pushswap_data *ps_data;

	argc = validate_inputs(argc, argv);
	ps_data = malloc(sizeof(t_pushswap_data));
	init_data (ps_data, argc, argv);

}
