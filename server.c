/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:49:36 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/02 15:17:26 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_handler(int sig)
{
	ft_printf("%c", sig);
}

int main()
{
	int pid;

	pid = getpid();
	ft_printf("The PID is: %d", pid);
	while(1)
	{
		signal(SIGUSR1, ft_handler);
		sleep (10);
	}
	
	return(0);
}