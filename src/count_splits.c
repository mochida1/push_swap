/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_splits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:10:52 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 16:53:23 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
** counts and returns the number of splitable elements in the string.
** Yes, it'll be used again in the split. Yes, it could be optmized.
** But I ain't giving a single fuck about it.
*/
int	count_splits(char *str)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str == '-')
			str++;
		while (*str && *str != ' ')
			str++;
		ret++;
		while (*str && *str == ' ')
			str++;
	}
	return (ret);
}
