/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:33:51 by recherra          #+#    #+#             */
/*   Updated: 2024/04/28 21:38:05 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        printf("too many/few arguments.");
        exit(1);
    }
    int pid;

    pid = ft_atoi(av[1]);
    printf("received pid => %c", pid);
    printf("%s\n", av[1]);
    kill(22033, SIGUSR1);

    return 0;
}