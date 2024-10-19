/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:28:43 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/10/19 17:38:07 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_binary(char c, int pid)
{
	int	i;
	int	j;

	i = 7;
	while (i >= 0)
	{
		j = ((c >> i) & 1);
		if (j == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(100);
	}
}

int	main(int ac, char *av[])
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
	{
		ft_printf("Error");
		return (1);
	}
	pid = ft_atoi(av[1]);
	kill(pid, SIGUSR1);
	while (av[2][i])
	{
		char_to_binary(av[2][i], pid);
		i++;
	}
	char_to_binary('\0', pid);
}
