/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:37:33 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 16:39:32 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
** Wrapper that inquires the user's inputs for demonic stuff.
** If no signs of foul characters are found, returns the number of splittable
** elements. Else exits with exit code 1.
*/
int	validate_inputs(int argc, char *argv[])
{
	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	argc = check_arguments(argv);
	if (argc < 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	return (argc);
}
