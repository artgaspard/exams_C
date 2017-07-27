/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:37:40 by agaspard          #+#    #+#             */
/*   Updated: 2017/01/05 15:10:50 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int			ft_conv(char c)
{
	int		res;

	if (c >= '0' && c <= '9')
		res = c - '0';
	else if (c >= 'A' && c <= 'F')
		res = c - 'A' + 10;
	else
		res = c - 'a' + 10;
	printf("%d\n", res);
	return (res);
}

int			ft_power(int str_base, int power)
{
	int		res;

	if (power == 0)
		return (1);
	if (power == 1)
		return (str_base);
	res = str_base;
	while (--power)
		res = res * str_base;
	printf("%d\n", res);
	return (res);
}

int			ft_atoi_base(char *str, int str_base)
{
	int		i;
	int		neg;
	int		res;
	int		power;
	int		len;

	i = 0;
	if (str_base == 0)
		return (0);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	neg = i;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	res = 0;
	power = 0;
	len = 0;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F')))
	{
		i++;
		len++;
	}
	i--;
	while (len--)
	{
		printf("%c\n", str[i]);
		res = res + (ft_conv(str[i]) * ft_power(str_base, power));
		i--;
		power++;
	}
	if (str[neg] == '-')
		return (-res);
	return (res);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%d\n", ft_atoi_base(av[1], atoi(av[2])));
	return(0);
}
