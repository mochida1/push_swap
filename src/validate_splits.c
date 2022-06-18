/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_splits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:51:30 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/17 23:33:36 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
** Parses a sequence of numbers, checking if it is valid while advancing the
** pointer until the next splittable element or null terminator;
*/
static int validate_pos_seq (char **str)
{
	while (ft_isnumber(**str))
		str[0]++;
	if (!**str)
		return (0);
	if (**str != ' ')
		return (1);
	while (**str == ' ')
		str[0]++;
	return (0);
}

/*
** parses a sequence starting at a '-' while advancing the pointer until the
** next splittable element or null terminator.
** If it's not good shizzle, returns 1, else returns 0;
*/
static int validate_neg_seq (char **str)
{
	str[0]++;
	if (!ft_isnumber(**str))
		return (1);
	while (ft_isnumber(**str))
		str[0]++;
	if (!**str)
		return (0);
	if (**str != ' ')
		return (1);
	while (**str == ' ')
		str[0]++;
	return (0);
}

/*
** validates the sequence of splittable elements to check if they're valid
** integers. Return 0 if no problems are found, else returns 1;
*/
int	validate_splits(char *str)
{
	char *temp;

	temp = str;
	while (*temp)
	{
		if (*temp == '-')
		{
			if (validate_neg_seq(&temp))
				return (1);
		}
		else if (ft_isnumber(*temp))
		{
			if (validate_pos_seq(&temp))
				return (1);
		}
		while (*temp == ' ')
			temp++;
	}
	return (0);
}
