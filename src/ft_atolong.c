/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:49:26 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/17 18:23:11 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char c)
{
	if (c == 32 || (c > 8 && c < 14))
		return ((int)c);
	else
		return (0);
}

long int		ft_atolong(const char *str)
{
	long int ret;
	int m;

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
