/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:29:17 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/10/19 16:32:52 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	binary_to_char(int word[8])
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		c |= (word[i] << (7 - i));
		i++;
	}
	return (c);
}

void	handle_signal(int signal)
{
	static int	i = 0;
	static int	word[8];
	char		c;

	c = 0;
	if (signal == SIGUSR1)
	{
		word[i] = 0;
		i++;
	}
	else if (signal == SIGUSR2)
	{
		word[i] = 1;
		i++;
	}
	if (i == 8)
	{
		c = binary_to_char(word);
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID - %d\n", pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
	return (0);
}
