/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:37:17 by asomanah          #+#    #+#             */
/*   Updated: 2024/06/18 15:40:53 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

char	*g_string;

static void	encode(int pid, char *str)
{
	char	i;
	char	letter;

	ft_printf("\n Sending message \n");
	while (*str)
	{
		i = 8;
		while (i--)
		{
			letter = *str >> i;
			if (letter & 1)
				kill (pid, SIGUSR2);
			else
				kill (pid, SIGUSR1);
			usleep (300);
		}
		str++;
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(200);
	}
}

static void	receive(int sig, siginfo_t *info, void *context)
{
	static pid_t	pid = 0;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	else if (pid != info->si_pid)
		return ;
	if (sig == SIGUSR1 && *g_string)
	{
		write (1, g_string, 1);
		usleep(200);
		g_string++;
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("\n Server (PID %i) end was recived \n", pid);
		pid = 0;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	action;

	if (argc != 3 || !ft_isint(argv[1]) || ft_atoi(argv[1]) < 0)
		ft_printf("#### Input Error #### \n");
	else
	{
		sigemptyset(&action.sa_mask);
		sigaddset(&action.sa_mask, SIGUSR1);
		sigaddset(&action.sa_mask, SIGUSR2);
		action.sa_flags = SA_RESTART | SA_SIGINFO;
		action.sa_sigaction = receive;
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		g_string = argv[2];
		encode(ft_atoi(argv[1]), argv[2]);
		while (*g_string)
			pause();
		usleep(20000);
	}
}
