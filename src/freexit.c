/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freexit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:29:13 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/18 15:14:17 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Frees pointer ptr and exits with exit_code;
*/
void	freexit(void *ptr, int exit_code)
{
	free (ptr);
	exit (exit_code);
}
