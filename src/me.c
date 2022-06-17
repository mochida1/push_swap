/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   me.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:46:15 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/16 20:52:44 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

int	main(int argc, char *argv[])
{
	int i = 0;
	printf("rodando! argc = %d\n", argc);
	while (argv[i])
	{
		printf("Sargv%d: %s\n", i, argv[i]);
		printf("Dargv[%d]: %d\n", i, argv[i][0]);
		i++;
	}
	i = 0;
	int count = 0;
	while (argv[i])
	{
		count += count_splits(argv[i++]);
	}
	printf("Count: %d\n", count);
	return(0);
}
