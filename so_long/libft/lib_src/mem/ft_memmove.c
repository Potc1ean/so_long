/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:48:24 by ichpakov          #+#    #+#             */
/*   Updated: 2024/04/15 02:40:35 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_ptr;
	char	*src_ptr;

	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (len--)
			*(dst_ptr + len) = *(src_ptr + len);
		return (dst);
	}
	while (len--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}
