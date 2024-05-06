/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:33:51 by recherra          #+#    #+#             */
/*   Updated: 2024/05/06 21:08:45 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	kill_err_handling(void)
{
	ft_putendl_fd("Error occured.", 2);
	exit(1);
}

void	send_len(int pid, int len)
{
	int	i;
	int	bit_v;

	i = 31;
	while (i >= 0)
	{
		bit_v = (len >> i) & 1;
		if (bit_v == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				kill_err_handling();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				kill_err_handling();
		}
		usleep(400);
		i--;
	}
}

void	send_bit(int pid, char a)
{
	int	i;
	int	bit_v;

	i = 7;
	while (i >= 0)
	{
		bit_v = (a >> i) & 1;
		if (bit_v == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				kill_err_handling();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				kill_err_handling();
		}
		usleep(400);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;
	int	arg_len;

	if (ac != 3)
	{
		ft_putendl_fd("too many/few arguments.", 2);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		kill_err_handling();
	i = 0;
	arg_len = ft_strlen(av[2]);
	send_len(pid, arg_len);
	while (av[2][i])
	{
		send_bit(pid, av[2][i]);
		i++;
	}
	return (0);
}
