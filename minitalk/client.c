/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:36:57 by mrio              #+#    #+#             */
/*   Updated: 2025/10/09 21:28:53 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_string(int pid, char *str)
{
	int	i;
	int	bit_pos;
	int	signal;

	i = 0;
	while (1)
	{
		bit_pos = 0;
		while (bit_pos < 8)
		{
			if (((str[i] >> bit_pos) & 1) == 0)
				signal = SIGUSR1;
			else
				signal = SIGUSR2;
			if (kill(pid, signal) == -1)
				exit(1);
			while (!g_ack_received)
				usleep(10);
			g_ack_received = 0;
			bit_pos++;
		}
		if (str[i] == '\0')
			break ;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
		return (0);
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (0);
	send_string(pid, argv[2]);
	return (0);
}
