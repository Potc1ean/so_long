/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:14:43 by ichpakov          #+#    #+#             */
/*   Updated: 2023/11/03 05:09:47 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	ts1;
	size_t	ts2;

	ts1 = ft_strlen(s1);
	ts2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (ts1 + ts2 + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, ts1 +1);
	res += ts1;
	ft_strlcpy(res, s2, ts2 + 1);
	res -= ts1;
	return (res);
}
