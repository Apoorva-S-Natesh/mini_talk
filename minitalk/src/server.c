/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:29:05 by asomanah          #+#    #+#             */
/*   Updated: 2024/06/18 16:03:30 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	end_message(pid_t *pid)
{
	ft_printf("\n complete message received from client %i\n", *pid);
	usleep(500);
	kill(*pid, SIGUSR2);
	usleep(20000);
	*pid = 0;
}

static void	decode(int sig, siginfo_t *info, void *context)
{
	static char		bit = 0;
	static char		letter = 0;
	static pid_t	pid = 0;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	else if (pid != info->si_pid)
		return ;
	if (sig == SIGUSR2)
		letter++;
	if (bit++ < 7)
		letter <<= 1;
	else
	{
		bit = 0;
		if (letter == 0)
			return (end_message(&pid));
		kill(info->si_pid, SIGUSR1);
		write(1, &letter, 1);
		letter = 0;
	}
	usleep(200);
}

int	main(void)
{
	struct sigaction	action;

	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	action.sa_flags = SA_RESTART | SA_SIGINFO;
	action.sa_sigaction = decode;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("\n Server Process ID: %d \n", getpid());
	while (1)
		pause();
	return (0);
}
