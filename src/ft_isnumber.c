/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:58:19 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/16 20:55:52 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

/*
** if char c is a number, returns it's ascii value;
** if not returns 0;
*/

int	ft_isnumber(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}