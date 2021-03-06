/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:49:26 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 16:50:12 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
** Just documenting this for procrastination's sake.
*/
static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}

/*
** It's atoi. But to long instead.
*/
long int	ft_atolong(const char *str)
{
	long	ret;
	int		m;

	ret = 0;
	m = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		m = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	if (ft_isdigit(*str))
		ret += *str++ - 48;
	while (ft_isdigit(*str))
	{
		ret *= 10;
		ret += *str++ - 48;
	}
	return (ret * m);
}
