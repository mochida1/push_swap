/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:44:48 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/18 16:55:20 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Tests if char c is a space defined character. If not returns 0.
*/
int	ft_isspace(const char c)
{
	if (c == 32 || (c > 8 && c < 14))
		return ((int)c);
	else
		return (0);
}
