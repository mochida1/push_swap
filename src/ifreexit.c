/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifreexit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:33:33 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/17 20:40:16 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Checks if ptr_to_check is not NULL. If it is, free's ptr_to_free and exits
** with exit_code.
*/
void	ifreexit(void *ptr_to_check, void *ptr_to_free, int exit_code)
{
	if (!ptr_to_check)
	{
		free(ptr_to_free);
		exit(exit_code);
	}
}
