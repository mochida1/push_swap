/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:17:16 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/16 10:32:04 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H


typedef struct s_stack
{
	int				num;
	unsigned char	indexed;
	struct s_stack	*next;
	struct s_stack	*prev;
} t_stack;




#endif