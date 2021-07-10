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
				kill(pid_serv, SIGUSR2);
			else
				kill(pid_serv, SIGUSR1);
			bit++;
			usleep(100);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;// ft_atoi ft_strlen ft_putstr ft_putchar

	if (ac != 3)
	{
		ft_putstr("The client takes as parameters : server_pid msg_to_send\n");
		return (1);
	}
	pid = ft_atoi(av[1]);// check atoi
	if (pid < 0 || pid > 99998)
	{
		ft_putstr("Invalide server_pid\n");
		return (1);
	}
	else
		start_send(pid, av[2]);		
	return (0);

}
