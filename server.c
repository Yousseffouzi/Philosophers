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

void    handle_signal(int signal, siginfo_t *info, void *context)
{
    static unsigned char    current_char;
    static int              bit_index;
    static pid_t            pid;

    (void)context;
    if (pid != info->si_pid)
	{
		pid = info->si_pid;
		current_char = 0;
		bit_index = 0;
	}
	current_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		write(1, &current_char, 1);
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;

}


int main(int ac, char **av)
{
    int pid;
    struct sigaction sa;

    (void)(**av);
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    pid = getpid();
    if(ac == 1)
    {
        ft_putnbr_fd(pid, 1);
        ft_putchar_fd('\n', 1);
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
        while (1337)
        {
            pause();
        }
    }
    else
        ft_putstr_fd("Input Error < no Input necessary >", 2);
}
