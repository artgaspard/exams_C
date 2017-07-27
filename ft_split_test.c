/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 09:28:00 by agaspard          #+#    #+#             */
/*   Updated: 2017/01/17 09:33:45 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int		ft_count_words(char *str)
{
	int i;
	int count;

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
