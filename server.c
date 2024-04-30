/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:33:45 by recherra          #+#    #+#             */
/*   Updated: 2024/04/30 21:22:25 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"



void handler(int signal)
{
    static unsigned char ch = 0;
    static int bits = 0;


    // printf("bits -> %d\n", bits);
    printf("ch -> %d\n", ch);
    ch = ch << 1;
    if (signal == SIGUSR2)
        ch = ch | 1;
    bits++;
    if (bits == 8)
    {

        printf("\n%d\n", ch);
        exit(1);
    }
    printf("\n");
}


int main()
{
    struct sigaction sa;

    sa.sa_handler = &handler;
    sa.sa_flags = 0;

    printf("%d\n", getpid());
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        ;
    return (0);
}