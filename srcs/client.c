/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:54:22 by suahn             #+#    #+#             */
/*   Updated: 2021/11/02 15:54:25 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_forward_signal(char c, int pid)
{
	int	bit_index;

	bit_index = 0;
	while (bit_index < 8)
	{
		if (((c >> (7 - bit_index)) & 1) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
		bit_index++;
	}
}

int	ft_is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_error_management(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		write(1, "Error: too many or too few arguments\n", 37);
		exit(EXIT_SUCCESS);
	}
	if (!ft_is_str_digit(argv[1]))
	{
		write(1, "Error: non-digit pid\n", 21);
		exit(EXIT_SUCCESS);
	}
	i = 0;
	while ((argc == 3) && (argv[2][i]))
	{
		if (argv[2][i] < 32 || argv[2][i] > 126)
		{
			write(1, "Error: non-printable character\n", 30);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	ft_error_management(argc, argv);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		ft_forward_signal(argv[2][i], pid);
		i++;
		usleep(50);
	}
	return (0);
}
