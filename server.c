/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:49:36 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/12 16:33:55 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_handler(int sig)
{
		if (sig == SIGUSR1)
			write (1, "1", 1);
		else if (sig == SIGUSR2)
			write (1, "0", 1);
}

int main()
{
	int pid;
	char *pidchar;
	int i;

	pid = getpid();
	i = 0;
	pidchar = ft_itoa(pid);
	write (1, "The PID is: ", 12);
	while(pidchar[i])
	{
		write(1, &pidchar[i], 1);
		i++;
	}
	write (1, "\n", 1);
	while(1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		sleep (100);
	}
	return(0);
}