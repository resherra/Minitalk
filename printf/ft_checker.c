/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:21:31 by recherra          #+#    #+#             */
/*   Updated: 2024/05/01 16:01:50 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(char c, va_list ptr)
{
	int	j;

	j = 0;
	if (c == 'd' || c == 'i')
		j += ft_putnbr(va_arg(ptr, int));
	else if (c == 's')
		j += ft_putstr(va_arg(ptr, char *));
	else if (c == 'c')
		j += ft_putchar(va_arg(ptr, int));
	else
		j += ft_putchar(c);
	return (j);
}
