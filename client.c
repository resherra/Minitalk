/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:33:51 by recherra          #+#    #+#             */
/*   Updated: 2024/04/30 20:05:05 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void send_bit(int pid, char a)
{
    int i = 7;
    while (i >= 0)
    {
        int bit_v = (a >> i) & 1;
        if (bit_v == 0)
        {
            kill(pid, SIGUSR1);
        }
        else
        {
            kill(pid, SIGUSR2);
        }
        usleep(200);
        i--;
    }
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        printf("too many/few arguments.");
        return 1;
    }

    int pid;
    pid = ft_atoi(av[1]);
    int i = 0;
    while (av[2][i])
    {
        send_bit(pid, av[2][i]);
        i++;
    }

    return 0;
}

// 0 1 1 0 1 0 0 0