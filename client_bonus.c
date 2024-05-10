/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:43:38 by recherra          #+#    #+#             */
/*   Updated: 2024/05/10 16:17:16 by recherra         ###   ########.fr       */
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
		usleep(300);
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
		usleep(300);
		i--;
	}
}

void	handler(int signal)
{
	(void)signal;
	ft_printf("Message sent successfully!\n");
	exit(0);
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
	signal(SIGUSR1, &handler);
	pid = ft_atoi(av[1]);
	i = 0;
	arg_len = ft_strlen(av[2]);
	send_len(pid, arg_len);
	while (av[2][i])
		send_bit(pid, av[2][i++]);
	while (1)
		pause();
	return (0);
}
