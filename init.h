/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:33:32 by recherra          #+#    #+#             */
/*   Updated: 2024/05/07 15:12:50 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <signal.h>

typedef struct s_len
{
	unsigned int				len;
	unsigned int				len_bits;
	int				old_pid;
	char			*str;

}					t_len;

typedef struct s_char
{
	unsigned char	ch;
	unsigned int				bits;
	unsigned int				i;
}					t_char;

#endif
