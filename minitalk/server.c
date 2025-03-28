/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:59:02 by mdinc             #+#    #+#             */
/*   Updated: 2025/02/18 16:03:04 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

static void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}

static void	get_signal(int signal)
{
	static int	counter = 7;
	static char	rec_char = 0;

	if (signal == 12)
	{
		rec_char = rec_char | (1 << counter);
	}
	counter--;
	if (counter == -1)
	{
		write(1, &rec_char, 1);
		counter = 7;
		rec_char = 0;
	}
}

int	main(void)
{
	write(1, "process id: ", 12);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(10, get_signal);
	signal(12, get_signal);
	while (1)
		;
	return (0);
}
