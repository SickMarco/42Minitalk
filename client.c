/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:49:32 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/12 16:33:48 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_text_send(int pid, char *str)
{
    char ch;
    int i;
    int x;

    while (str[x])
    {
        i = 8;
        ch = str[x];
        while (i > 0)
        {
            if (ch >> i & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            i--;
            usleep(100);
        }
        x++;
    }
}

int main(int argc, char **argv)
{
	int pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_text_send(pid, argv[2]);
	}
	return (0);
}

