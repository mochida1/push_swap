/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:44:48 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/17 22:30:51 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

static int check_int_xflow (long nbr, t_pushswap_data *ps_data)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
	{
		ft_putstr_fd(PSERROR, 2);
		free(ps_data->lut);
		freexit(ps_data, 2);
	}
	return ((int) nbr);
}

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
			printf ("LUT[%d]: %d\n", i+1, ps_data->lut[i]);
			i++;
			while (*temp && *temp != ' ')
				temp++;
		}
		j++;
	}
}

void	get_lut(t_pushswap_data *ps_data, char *argv[])
{
	ps_data->lut = malloc (sizeof(int) * ps_data->ele_count);
	ifreexit(ps_data->lut, ps_data, 1);
	fill_lut(ps_data, argv);
}
