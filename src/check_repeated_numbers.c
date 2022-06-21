/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_repeated_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:31:04 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 16:54:00 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
** This is already sorted. My job here is done.
*/
static void	is_only_one_element(t_pushswap_data *ps_data)
{
	if (ps_data->ele_count == 1)
	{
		freedom(ps_data);
		exit (0);
	}
}

/*
** Fuck this shit I'm out - hmmm hmmm hmmmmm!
*/
static void	this_should_not_happen(t_pushswap_data *ps_data)
{
	freedom(ps_data);
	ft_putstr_fd(PSERROR, 2);
	exit (1);
}

/*
** Checks the LUT for repeated numbers. If it is repeated, frees all pointers
** and exits with code 1. Also deals with cases of only one input.
*/
void	check_repeated_numbers(t_pushswap_data *ps_data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	is_only_one_element(ps_data);
	while (i < ps_data->ele_count)
	{
		while (j < ps_data->ele_count)
		{
			if (ps_data->lut[i] == ps_data->lut[j])
				this_should_not_happen(ps_data);
			else
				j++;
		}
		i++;
		j = i + 1;
	}
}
