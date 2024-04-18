/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:36:09 by ichpakov          #+#    #+#             */
/*   Updated: 2024/04/15 03:22:44 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

void	*ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}
