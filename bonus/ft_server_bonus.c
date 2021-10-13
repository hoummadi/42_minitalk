/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:07:42 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/09 19:07:44 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n < -9)
			ft_putnbr_fd(-(n / 10), fd);
		ft_putchar_fd(-(n % 10) + 48, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

void	receive_bit(int sig)
{
	static int	size;
	static char	to_print;

	to_print += ((sig % 2) << size);
	size++;
	if (size == 8)
	{
		ft_putchar_fd(to_print, 1);
		if (!to_print)
			ft_putchar_fd('\n', 1);
		to_print = 0;
		size = 0;
	}
}

int	main(int ac, char **av)
{
	int	serv_pid;

	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("No arguments needed.\n", 2);
		return (1);
	}
	ft_putstr_fd("server pid : ", 1);
	serv_pid = getpid();
	ft_putnbr_fd(serv_pid, 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
		signal(SIGUSR2, receive_bit);
		signal(SIGUSR1, receive_bit);
		pause();
	}
	return (0);
}
