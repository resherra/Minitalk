/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:33:51 by recherra          #+#    #+#             */
/*   Updated: 2024/05/01 17:45:13 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void send_len(int pid, int len)
{
    int i = 31;
    while (i >= 0)
    {
        int bit_v = (len >> i) & 1;
        if (bit_v == 0)
        {
            if (kill(pid, SIGUSR1) == -1)
            {
                ft_putendl_fd("Error occured.", 2);
                exit(1);
            }
        }
        else
        {
            if (kill(pid, SIGUSR2) == -1)
            {
                ft_putendl_fd("Error occured.", 2);
                exit(1);
            }
        }
        usleep(200);
        i--;
    }
}

void send_bit(int pid, char a)
{
    int i = 7;
    while (i >= 0)
    {
        int bit_v = (a >> i) & 1;
        if (bit_v == 0)
        {
            if (kill(pid, SIGUSR1) == -1)
            {
                ft_putendl_fd("Error occured.", 2);
                exit(1);
            }
        }
        else
        {
            if (kill(pid, SIGUSR2) == -1)
            {
                ft_putendl_fd("Error occured.", 2);
                exit(1);
            }
        }
        usleep(300);
        i--;
    }
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        ft_putendl_fd("too many/few arguments.", 2);
        return 1;
    }
    int pid;
    pid = ft_atoi(av[1]);
    if (pid <= 0)
        ft_putendl_fd("Invalid PID.", 2);
    int i = 0;
    int arg_len = ft_strlen(av[2]);
    send_len(pid, arg_len);
    while (av[2][i])
    {
        send_bit(pid, av[2][i]);
        i++;
    }
    
    return 0;
}
