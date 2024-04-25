/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:08:40 by ichpakov          #+#    #+#             */
/*   Updated: 2024/04/15 02:40:40 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bb;

	i = 0;
	bb = (unsigned char *)b;
	while (i < len)
	{
		bb[i] = c;
		i++;
	}
	return (b = bb);
}
