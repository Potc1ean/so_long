/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:32:57 by ichpakov          #+#    #+#             */
/*   Updated: 2023/11/03 04:24:57 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*res;

	len = ft_strlen(s1);
	start = 0;
	end = len;
	if (s1 == NULL)
		return (NULL);
	while (start < len && (ft_strchr(set, s1[start]) != NULL))
		start++;
	while (end > start && (ft_strchr(set, s1[end - 1]) != NULL))
		end--;
	len = end - start;
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1 + start, len + 1);
	res[len] = '\0';
	return (res);
}
