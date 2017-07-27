/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:06:20 by agaspard          #+#    #+#             */
/*   Updated: 2017/01/28 15:13:12 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int i;

	i = 0;
	len++;
	while (--len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (len--)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char *dst;

	if ((dst = (char*)malloc(sizeof(char) * (n + 1))) == 0)
		return (NULL);
	ft_strncpy(dst, s1, n);
	return (dst);
}

int		main(void)
{
	printf("%s\n", ft_strndup("coucou", 1));
	return (0);
}
