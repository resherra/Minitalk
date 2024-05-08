/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:33:45 by recherra          #+#    #+#             */
/*   Updated: 2024/05/07 15:28:07 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	reset_values(t_len *data, t_char *packet, pid_t new_pid)
{
	data->len = 0;
	data->len_bits = 0;
	packet->ch = 0;
	packet->bits = 0;
	packet->i = 0;
	data->old_pid = new_pid;
}

void	get_string(t_len *data, t_char *packet, int signal)
{
	packet->ch = packet->ch << 1;
	if (signal == SIGUSR2)
		packet->ch = packet->ch | 1;
	packet->bits++;
	if (packet->bits == 8)
	{
		data->str[packet->i] = packet->ch;
		packet->i++;
		packet->ch = 0;
		packet->bits = 0;
	}
	if (packet->i == data->len)
	{
		ft_printf("%s", data->str);
		free(data->str);
		data->len_bits = 0;
		data->len = 0;
		packet->i = 0;
	}
}

void	handler(int signal, siginfo_t *info, void *context)
{
	static t_len	data;
	static t_char	packet;

	(void)context;
	if (data.old_pid != info->si_pid)
	{
		reset_values(&data, &packet, info->si_pid);
		//printf("%")
	}
	if (data.len_bits != 32)
	{
		// ft_printf("\ndata len bits %d\n", data.len_bits);
		data.len = data.len << 1;
		if (signal == SIGUSR2)
			data.len = data.len | 1;
		data.len_bits++;
		if (data.len_bits == 32)
		{
			data.len_bits = 32;
			data.str = malloc(data.len + 1);
			if (data.str == NULL)
			{
				reset_values(&data, &packet, info->si_pid);
				return ;
			}
			ft_printf("\nlen --> %d\n", data.len);
			
//			data.str[data.len] = 0;
		}
	}
	else
		get_string(&data, &packet, signal);
}

int	main(int ac, char **av)
{
	struct sigaction	signals;

	(void)av;
	if (ac != 1)
	{
		ft_putendl_fd("Too many arguments.", 2);
		return (1);
	}
	ft_printf("Server pid: %d\n", getpid());
	signals.sa_sigaction = handler;
	sigemptyset(&signals.sa_mask);
	sigaddset(&signals.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &signals, NULL);
	sigaction(SIGUSR2, &signals, NULL);
	while (1)
		pause();
	return (0);
}
