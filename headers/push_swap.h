/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:19:18 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/16 20:56:15 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h> // read, write;
#include <stdlib.h> // exit, malloc, free;
#include <stdio.h> // DELETAR OS PRINTF!!!
#include "defs.h"

char **push_swap(int argc, char *argv[]);
int	check_arguments (char *argv[]);
int count_splits (char *argv);
int	validate_splits(char *str);
int check_invalid_chars (char *str);
int	ft_isnumber(int c);

#endif