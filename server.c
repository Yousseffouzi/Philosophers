/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yofouzi@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:36:37 by root              #+#    #+#             */
/*   Updated: 2025/03/24 01:36:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char **av)
{
    int pid;
    struct sigaction    sa;

    sa.sa_sigaction = handel_signal;
    sa.sa_flags = SA_SIGINFO;
    pid = getpid();
    if(ac == 1)
    {
        ft_putnbr_fd(pid, 1);
        ft_putchar_fd('\n', 1);
        sigaction()

    }
}
