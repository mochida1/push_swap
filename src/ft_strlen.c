/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:46:55 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/18 15:21:13 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Counts how many characters a string has.
*/
int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
