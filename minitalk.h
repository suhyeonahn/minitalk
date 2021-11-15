/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:54:02 by suahn             #+#    #+#             */
/*   Updated: 2021/11/02 15:54:09 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_signal_handler(int sig_num);
void	ft_forward_signal(char c, int pid);
int		ft_is_str_digit(char *str);
void	ft_error_management(int argc, char **argv);
int		ft_atoi(const char *str);
void	ft_putnbr(long n);
void	ft_putchar(char c);

#endif
