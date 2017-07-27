/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:32:27 by agaspard          #+#    #+#             */
/*   Updated: 2017/01/11 15:50:59 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_wstr(char *str, int first)
{
	int	i;
	int start;

	i = 0;
	if (str[i])
	{
		while (str[i] && str[i] <= 32)
			i++;
		if (!str[i])
			return ;
		start = i;
		while (str[i] && str[i] > 32)
			i++;
		ft_rev_wstr(&str[i], 0);
		write(1, &str[start], i - start);
		if (!first)
			write(1, " ", 1);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_rev_wstr(av[1], 1);
	write(1, "\n", 1);
	return (0);
}
