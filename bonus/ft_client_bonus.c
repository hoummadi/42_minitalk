/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:08:08 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/09 19:08:09 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	free_str(char *to_free, int isfree)
{
	if (isfree == 1)
		free(to_free);
}

void	kill_faild(char *to_free, int isfree)
{
	ft_putstr_fd("Failed to send message, check server pid!\n", 2);
	free_str(to_free, isfree);
	exit(1);
}

void	start_send(int pid_serv, char *to_send, int isfree)
{
	int	bit;
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(to_send);
	while (i < len)
	{
		bit = 0;
		while (bit < 8)
		{
			if ((to_send[i] >> bit) & 1)
			{
				if (kill(pid_serv, SIGUSR2) == -1)
					kill_faild(to_send, isfree);
			}
			else
				if (kill(pid_serv, SIGUSR1) == -1)
					kill_faild(to_send, isfree);
			bit++;
			usleep(100);
		}
		i++;
	}
	free_str(to_send, isfree);
}

int	main(int ac, char **av)
{
	int	pid;
	int	cli_pid;

	if (ac != 3)
	{
		ft_putstr_fd("Client takes as parameters : server_pid msg\n", 2);
		return (1);
	}
	cli_pid = getpid();
	pid = checkatoi(av[1]);
	if (pid < 0 || pid > 99998)
	{
		ft_putstr_fd("Invalide server_pid\n", 2);
		return (1);
	}
	else
	{
		start_send(pid, "This message from ", 0);
		start_send(pid, ft_itoa(cli_pid), 1);
		start_send(pid, " :\n", 0);
		start_send(pid, ft_strjoin(av[2], "\n"), 1);
	}
	ft_putstr_fd("Message sent successfully to ", 1);
	ft_putendl_fd(av[1], 1);
	return (0);
}
