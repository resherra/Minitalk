/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:33:45 by recherra          #+#    #+#             */
/*   Updated: 2024/04/28 16:33:46 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void signal_handler(int signum)
{
//    printf("Received SIGINT!\n", signum);
    printf("%d\n", signum);
    exit(0);
}

int main()
{
    sigset_t signal_set;
    struct sigaction action;


    sigemptyset(&signal_set);



    sigaddset(&signal_set, SIGQUIT);
    printf("%d\n", signal_set);
    sigaddset(&signal_set, SIGKILL);
    printf("%d\n", signal_set);




    return 0;
}