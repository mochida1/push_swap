/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:19:18 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/17 19:54:48 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h> // read, write;
#include <stdlib.h> // exit, malloc, free;
#include <stdio.h> // DELETAR OS PRINTF!!!
#include "defs.h"

int	check_arguments (char *argv[]);
int check_invalid_chars (char *str);
int count_splits (char *argv);
long int	ft_atolong(const char *str);
int	ft_isnumber(int c);
long int	ft_atolong(const char *str);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
char	*ft_strdup(const char *s1);
int	ft_strlen(const char *s);
void	init_data(t_pushswap_data *ps_data, int argc, char *argv[]);
char **push_swap(int argc, char *argv[]);
int validate_inputs(int argc, char *argv[]);
int	validate_splits(char *str);

#endif
