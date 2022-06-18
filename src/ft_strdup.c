/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:43:18 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/18 15:20:37 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

/*
** Copies a string and returns a new pointer.
*/
char	*ft_strdup(const char *s1)
{
	int		l;
	char	*c;
	int		i;

	i = 0;
	l = ft_strlen(s1) + 1;
	c = malloc(l * (sizeof(char)));
	if (!c)
		return (0);
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
