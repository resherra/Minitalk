/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:33:45 by recherra          #+#    #+#             */
/*   Updated: 2024/05/01 18:00:20 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"


void len_handler(int signal, siginfo_t *info, void *context)
{
    (void)info;
    (void)context;
    printf("signal -> %d\n", signal);
    static int len = 0;
    static int bits  = 0;

    len = len << 1;
    if (signal == SIGUSR2)
        len = len | 1;
    bits++;
    if (bits == 32)
    {
        ft_printf("len -> %d\n", len);
        exit(1);
    }
}

void string_handler(int signal, siginfo_t *info, void *context)
{
    // printf("sending process -> %d\n", info->si_pid);
    (void)info;
    (void)context;
    static unsigned char ch = 0;
    static int bits = 0;
    
    ch = ch << 1;
    if (signal == SIGUSR2)
        ch = ch | 1;
    bits++;
    if (bits == 8)
    {
        ft_printf("%c", ch);
        ch = 0;
        bits = 0;
    }
}


int main(int ac, char **av)
{
    (void)av;
    if (ac != 1)
    {
        ft_putendl_fd("Too many arguments.", 2);
        return 1;
    }
    struct sigaction signals;
    struct sigaction len;


    len.sa_sigaction = &len_handler;
    len.sa_flags = 0;
    signals.sa_sigaction = &string_handler;
    signals.sa_flags = 0;

    ft_printf("%d\n", getpid());
    sigaction(SIGUSR1, &len, NULL);
    sigaction(SIGUSR2, &len, NULL);

    while (1)
        ;

    // sigaction(SIGUSR1, &signals, NULL);
    // sigaction(SIGUSR2, &signals, NULL);

    return (0);
}