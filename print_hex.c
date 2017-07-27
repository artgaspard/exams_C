/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 10:35:48 by agaspard          #+#    #+#             */
/*   Updated: 2017/01/03 11:02:00 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	int		conv_nbr[64];
	int		base;
	int		i;
	int		value;
	char	tab[2] = {'0', '1'};

	i = 0;
	base = 2;
	value = atoi(av[1]);
	if (ac == 2)
	{
		while (value != 0)
		{
			conv_nbr[i] = value % base;
			value = value / base;
			++i;
		}
		--i;
		while (i >= 0)
		{
			write(1, &tab[conv_nbr[i]], 1);
			i--;
		}
		write(1, "\n", 1);
	}
	return (0);
}
