/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:26:12 by yofouzi           #+#    #+#             */
/*   Updated: 2025/04/04 13:26:17 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bit_index;
	static pid_t			pid;

	(void)context;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		current_char = 0;
		bit_index = 0;
	}
	current_char |= (signal == SIGUSR1);
	if (++bit_index == 8)
	{
		if (current_char == '\0')
			kill(info->si_pid, SIGUSR2);
		write(1, &current_char, 1);
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
	kill(info->si_pid, SIGUSR1);
	usleep(200);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)(**av);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (ac == 1)
	{
		ft_putnbr_fd(getpid(), 1);
		ft_putchar_fd('\n', 1);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1337)
		{
			pause();
		}
	}
}
