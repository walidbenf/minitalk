/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-far <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:16:22 by wben-far          #+#    #+#             */
/*   Updated: 2021/12/18 12:20:42 by wben-far         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <signal.h>

static void	ft_send(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit != -1)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		usleep(100);
	}
}

static void	ft_putstr(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send(pid, str[i]);
		i++;
	}
	ft_send(pid, '\0');
}

static int	ft_atoi(const char *str)
{
	int	result;
	int	negative;

	negative = 1;
	result = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		++str;
	}
	return (result * negative);
}

int	main(int argc, char*argv[])
{
	pid_t	pid;
	char	*str;

	if (argc < 3)
	{
		write(1, "\e[0;31mclient: arguments invalides\n", 37);
		write(2, "\e[0;31mformat incorrect : SERVER_PID MESSAGE\n", 47);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	ft_putstr(pid, str);
	return (0);
}
