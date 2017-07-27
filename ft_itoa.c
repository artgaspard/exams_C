/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 09:11:37 by agaspard          #+#    #+#             */
/*   Updated: 2017/01/17 09:24:26 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *str)
{
	int i;
	int j;
	char *cpy;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	if (str)
	{
		cpy = (char*)malloc(sizeof(char) * i + 1);
		if (cpy)
		{
			while (str[j])
			{
				cpy[j] = str[j];
				j++;
			}
			cpy[j] = '\0';
			return (cpy);
		}
	}
	return (0);
}

void	ft_itoa_neg(*nb, *neg)
{
	if (*nb < 0)
	{
		*nb *= -1;
		*neg = 1;
	}
}

char	*ft_itoa(int nb)
{
	int neg;
	int tmp;
	int len;
	char *str;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	tmp = nb;
	len = 2;
	ft_itoa_neg(&nb, &neg);
	while (tmp /= 10)
		len++;
	len = len + neg;
	if ((str = (char*)malloc(sizeof(char) * len)) == 0)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
