/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:50:53 by ichpakov          #+#    #+#             */
/*   Updated: 2023/11/03 16:50:37 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		dest = malloc(sizeof(char));
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
	}
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		dest = malloc(sizeof(char) * (len + 1));
		if (dest == NULL)
			return (NULL);
		i = 0;
		while (++i - 1 < len)
			*(dest + i - 1) = *(s + start + i - 1);
		*(dest + i - 1) = '\0';
	}
	return (dest);
}
