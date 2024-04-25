/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 04:11:35 by ichpakov          #+#    #+#             */
/*   Updated: 2024/04/24 03:41:07 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

int	ft_isnotcharset(char c, char *set)
{
	size_t	a;

	a = 0;
	while (set[a])
	{
		if (c != set[a])
			return (1);
		a++;
	}
	return (0);
}
