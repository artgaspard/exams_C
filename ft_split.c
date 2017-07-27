/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:11:13 by agaspard          #+#    #+#             */
/*   Updated: 2017/01/23 13:51:51 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strndup(char *str, int n)
{
	int		i;
	char	*cpy;

	if ((cpy = (char*)malloc(sizeof(char) * (n + 1))) == 0)
		return (NULL);
	i = 0;
	while (*str && i < n)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static int	ft_count_words(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		while (str[i] <= 32)
			i++;
		if (str[i])
		{
			count++;
			while (str && str[i] > 32)
				i++;
		}
	}
	return (count);
}

char		**ft_split(char *str)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(split = (char**)malloc(sizeof(char*) * (ft_count_words(str) + 1))))
		return (split);
	while (str && str[i])
	{
		while (*str && *str <= 32)
			str++;
		if (*str)
		{
			while (str && str[i] > 32)
				i++;
			split[j] = ft_strndup(str, i);
			j++;
			str = str + i;
			i = 0;
		}
	}
	split[j] = NULL;
	return (split);
}
