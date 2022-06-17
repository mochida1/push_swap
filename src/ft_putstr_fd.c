/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 04:59:21 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/17 18:30:00 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = (size_t)ft_strlen(s) * sizeof(char);
	write(fd, s, len);
}
