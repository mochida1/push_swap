/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_chars.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:37:58 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/16 19:02:59 by hmochida         ###   ########.fr       */
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
	while (*str)
	{
		if (*str == ' ' || ft_isnumber(*str) || *str == '-')
		{
			str++;
		}
		else
			return (1);
	}
	return (0);
}