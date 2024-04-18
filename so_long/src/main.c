/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 07:21:13 by ichpakov          #+#    #+#             */
/*   Updated: 2024/04/14 22:21:22 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void free_all(t_data data)
{
	
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_error("Error\nThis programe take 1 argument .ber\n");
		return (0);
	}
	else
	{
		data.count = 0;
		data.mlx_ptr = mlx_init();
		set_content(&(data.content));
		data.map = map_core(argv, &data);
		if (data.map != NULL)
		{
			set_img(&data);
			core_render(&data);
		}
		else
			end(&data);
	}
	free_all(data);
	return (1);
}
