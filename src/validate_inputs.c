/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:37:33 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/17 19:42:43 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

int	validate_inputs(int argc, char *argv[])
{
	if (argc==1)
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
