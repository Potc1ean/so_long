/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:02:38 by ichpakov          #+#    #+#             */
/*   Updated: 2023/10/30 19:25:22 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	t;

	t = ft_strlen(s1) + 1;
	res = malloc(sizeof(char) * t);
	if (!res)
		return (0);
	res = ft_memcpy(res, s1, t);
	return (res);
}
