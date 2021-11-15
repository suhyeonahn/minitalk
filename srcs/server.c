/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:54:42 by suahn             #+#    #+#             */
/*   Updated: 2021/11/02 15:54:44 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal_handler(int sig_num)
{
	static int	bit_index;
	static char	c;
	char		temp;

	temp = 0;
	if (bit_index < 8)
	{
		if (sig_num == SIGUSR1)
		{
			temp += 1;
			temp = temp << (7 - bit_index);
			c += temp;
		}
		bit_index++;
	}
	if (bit_index == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit_index = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;
	sigset_t			block_mask;

	pid = getpid();
	write(1, "Server PID : ", 13);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	action.sa_mask = block_mask;
	action.sa_handler = ft_signal_handler;
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
