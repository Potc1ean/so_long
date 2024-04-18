/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:41:46 by ichpakov          #+#    #+#             */
/*   Updated: 2023/10/30 19:51:03 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;
	size_t	i;

	total_size = count * size;
	ptr = malloc(total_size);
	i = 0;
	if (ptr != NULL)
	{
		while (i < total_size)
		{
			*((char *)ptr + i) = 0;
			i++;
		}
	}
	return (ptr);
}
