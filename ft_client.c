/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:07:13 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/09 19:07:15 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

void	kill_faild(void)
{
	ft_putstr("Failed to send message, check server pid!\n");
	exit(1);
}

void	start_send(int pid_serv, char *to_send)
{
	int	bit;
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(to_send);
	while (i <= len)
	{
		bit = 0;
		while (bit < 8)
		{
			if ((to_send[i] >> bit) & 1)
			{
				if (kill(pid_serv, SIGUSR2) == -1)
					kill_faild();
			}
			else
				if (kill(pid_serv, SIGUSR1) == -1)
					kill_faild();
			bit++;
			usleep(100);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;// ft_atoi ft_strlen ft_putstr ft_putchar ft_itoa
	int	cli_pid;

	if (ac != 3)
	{
		ft_putstr("The client takes as parameters : server_pid msg_to_send\n");
		return (1);
	}
	cli_pid = getpid();
	pid = ft_atoi(av[1]);// check atoi
	if (pid < 0 || pid > 99998)
	{
		ft_putstr("Invalide server_pid\n");
		return (1);
	}
	else
	{
		start_send(pid, "this message from ");
		start_send(pid, ft_itoa(cli_pid));
		start_send(pid, " :\n");
		start_send(pid, av[2]);
	}
	ft_putstr("Message sent successfully\n");
	return (0);

}
