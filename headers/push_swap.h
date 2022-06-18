/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:19:18 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/17 23:20:06 by hmochida         ###   ########.fr       */
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
void create_stack(t_pushswap_data *ps_data);
void	freexit(void *ptr, int exit_code);
long int	ft_atolong(const char *str);
int	ft_isnumber(int c);
long int	ft_atolong(const char *str);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
char	*ft_strdup(const char *s1);
int	ft_strlen(const char *s);
void	get_lut(t_pushswap_data *data, char *argv[]);
void	ifreexit(void *ptr_to_check, void *ptr_to_free, int exit_code);
void	init_data(t_pushswap_data *ps_data, int in_nbr, char *argv[]);
char **push_swap(int argc, char *argv[]);
int validate_inputs(int argc, char *argv[]);
int	validate_splits(char *str);

#endif
