/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:40:43 by ichpakov          #+#    #+#             */
/*   Updated: 2024/04/15 02:40:31 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	dest_ptr = (char *)dst;
	src_ptr = (const char *)src;
	while (n--)
		dest_ptr[n] = src_ptr[n];
	return (dst);
}
