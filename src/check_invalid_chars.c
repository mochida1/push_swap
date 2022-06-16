/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_chars.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:37:58 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/16 17:44:12 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
** checks if strings are all composed of SPACES and NUMBERS
** Returns 1 if it finds bad shit, if all is good and the user didn't try to
** fuck you up, it'll return 0 :)
*/

int check_invalid_chars (char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == ' ' || (str >= '0' && str <= '9'))
		{
			i++;
		}
		else
			return (1);
	}
	return (0);
}