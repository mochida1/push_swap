/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:28:33 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 16:55:11 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
** iterates through the arguments checking wether they're all numeric or spaces.
** counts the number of split elements and returns it.
** If an invalid character is found or if
** a splittable sequence has not a valid format, returns -1;
*/
int	check_arguments(char *argv[])
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	while (argv[i])
	{
		if (check_invalid_chars(argv[i]))
			return (-1);
		if (validate_splits(argv[i]))
			return (-1);
		ret += count_splits(argv[i]);
		i++;
	}
	return (ret);
}
