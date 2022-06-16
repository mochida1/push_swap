/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:32:17 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/16 09:42:10 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"
//char	**push_swap;

int	main(int argc, char *argv[])
{
	int i = 0;
	printf("rodando! argc = %d\n", argc);
	while (argv[i])
	{
		printf("argv%d: %s\n", i, argv[i]);
		i++;
	}
	
	return(0);
}