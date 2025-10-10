/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:29:16 by mrio              #+#    #+#             */
/*   Updated: 2025/10/09 21:52:02 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	current_char = 0;
	static int				bit_pos = 0;
	static int				client_pid = 0;

	(void)context;
	if (info->si_pid != 0)
		client_pid = info->si_pid;
	if (sig == SIGUSR2)
		current_char |= (1 << bit_pos);
	bit_pos++;
	if (bit_pos == 8)
	{
		if (current_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &current_char, 1);
		current_char = 0;
		bit_pos = 0;
	}
	if (client_pid)
		kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	write(1, "Server PID: ", 13);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(1);
	while (1)
		pause();
	return (0);
}
