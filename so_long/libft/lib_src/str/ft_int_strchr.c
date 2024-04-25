/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_strchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 03:41:52 by ichpakov          #+#    #+#             */
/*   Updated: 2024/04/24 03:38:55 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

int	ft_int_strchr(const char *s, int c)
{
	int	a;

	a = 0;
	if (!s)
		return (-1);
	while (s[a])
	{
		if (s[a] == (char)c)
			return (a);
		a++;
	}
	if (s[a] == (char)c)
		return (a);
	return (-1);
}
