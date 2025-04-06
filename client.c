/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:25:05 by yofouzi           #+#    #+#             */
/*   Updated: 2025/04/04 13:25:07 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_sas = 0;

void	handler(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		g_sas = 1;
	else if (signal == SIGUSR2)
		ft_putstr_fd("message recived\n", 1);
}

void	send_signal(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_sas = 0;
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_puterror_fd("Error: Failed to send SIGUSR1\n", 2);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_puterror_fd("Error: Failed to send SIGUSR2\n", 2);
		}
		while (!g_sas)
			pause();
		usleep(200);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int					server_pid;
	int					i;
	const char			*message;
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 3)
		ft_puterror_fd("Usage: ./client <pid> <message>\n", 2);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		exit(1);
	message = argv[2];
	i = 0;
	while (message[i])
		send_signal(server_pid, message[i++]);
	send_signal(server_pid, '\n');
	send_signal(server_pid, '\0');
	return (0);
}
