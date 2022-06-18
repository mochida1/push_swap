/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:44:48 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/18 15:27:33 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

/*
** Checks if the user is trying to fuck you up by inputing a number bigger than
** INT_MAX or smaller than INT_MIN. If so, prints Error\n,
** frees all allocated pointers and exits with code 1.
*/
static int check_int_xflow (long nbr, t_pushswap_data *ps_data)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
	{
		ft_putstr_fd(PSERROR, 2);
		free(ps_data->lut);
		freexit(ps_data, 1);
	}
	return ((int) nbr);
}

/*
** Converts all numbers from an array of strings to int then
** fill's up the allocated space with given int.
*/
static void fill_lut(t_pushswap_data *ps_data, char *argv[])
{
	char *temp;
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < ps_data->ele_count && argv[j])
	{
		temp = argv[j];
		while(*temp)
		{
			ps_data->lut[i] = check_int_xflow(ft_atolong(temp), ps_data);
			i++;
			while (*temp && *temp != ' ')
				temp++;
		}
		j++;
	}
}

/*
** Gets the Look Up Table from argv allocates and saves it on ps_data->lut;
*/
void	get_lut(t_pushswap_data *ps_data, char *argv[])
{
	ps_data->lut = malloc (sizeof(int) * ps_data->ele_count);
	ifreexit(ps_data->lut, ps_data, 1);
	fill_lut(ps_data, argv);
}
