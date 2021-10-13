/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:31:24 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/10 10:31:27 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	lena(long n)
{
	if (n <= 9)
		return (1);
	return (lena(n / 10) + 1);
}

static void	remp(char *s, long j, int i)
{
	if (j <= 9)
		s[--i] = j + '0';
	else
	{
		s[--i] = (j % 10) + '0';
		remp(s, j / 10, i);
	}
}

char	*ft_itoa(int n)
{
	long	j;
	int		i;
	char	*s;

	j = (long)n;
	i = 0;
	if (j < 0)
	{
		i = 1;
		j = -j;
	}
	n = lena(j);
	if (!n)
		return (NULL);
	s = malloc(1 + i + n);
	if (!s)
		return (0);
	remp(s, j, n + i);
	s[n + i] = '\0';
	if (i == 1)
		s[0] = '-';
	return (s);
}

static int	ft_atoi(char *str)
{
	long	r;
	int		i;

	r = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		else if (r <= ((INT_MAX - (str[i] - 48)) / 10))
			r = r * 10 + (str[i] - 48);
		else
			return (-1);
		i++;
	}
	return ((int)(r));
}

int	checkatoi(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	j = 0;
	while (str[j] && str[j] == '0')
		j++;
	if (i - j > 6)
		return (-1);
	return (ft_atoi(str));
}
