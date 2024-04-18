/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mouv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 07:20:55 by ichpakov          #+#    #+#             */
/*   Updated: 2024/03/19 07:20:56 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	*values(char d, int *res)
{
	res[0] = 0;
	res[1] = 0;
	if (d == 't')
		res[0] = -1;
	if (d == 'r')
		res[1] = 1;
	if (d == 'l')
		res[1] = -1;
	if (d == 'd')
		res[0] = 1;
	return (res);
}

void	render_dir(t_data *data, char direction)
{
	int		dir[2];
	int		pos_x;
	int		pos_y;

	values(direction, dir);
	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y + dir[0]][pos_x + dir[1]] != data->content.wall)
	{
		if (!(data->map[pos_y + dir[0]][pos_x + dir[1]] == data->content.exit))
		{
			data->map[pos_y + dir[0]][pos_x + dir[1]] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				printf("Vous avez gagne en : %d coup !\n", data->count);
				end(data);
			}
		}
	}
}
