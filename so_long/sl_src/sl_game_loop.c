/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 05:23:47 by ichpakov          #+#    #+#             */
/*   Updated: 2024/04/24 22:18:28 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sl_inc/so_long.h"

int	sl_close_window(t_prog *mlx)
{
	size_t	a;

	a = 0;
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	while (a <= 4)
	{
		mlx_destroy_image(mlx->ptr, mlx->iptr[a]);
		mlx->iptr[a] = NULL;
		a++;
	}
	mlx->ptr = NULL;
	mlx->win = NULL;
	a = sl_err2(19);
	exit(mlx->iloop);
	return (1);
}

static int	sl_checkdest(int key, t_prog *mlx)
{
	int	p;

	p = ft_int_strchr(mlx->map, 'P');
	if (key == K_W || key == K_UP)
	{
		if (!sl_check_tile(&*mlx, mlx->map[p - mlx->xnb - 1]))
			return (sl_err1(9));
	}
	else if (key == K_A || key == K_LEFT)
	{
		if (!sl_check_tile(&*mlx, mlx->map[p - 1]))
			return (sl_err1(10));
	}
	else if (key == K_S || key == K_DOWN)
	{
		if (!sl_check_tile(&*mlx, mlx->map[p + mlx->xnb + 1]))
			return (sl_err1(11));
	}
	else if (key == K_D || key == K_RIGHT)
	{
		if (!sl_check_tile(&*mlx, mlx->map[p + 1]))
			return (sl_err1(12));
	}
	return (p);
}

static int	sl_display_map(t_prog mlx)
{
	int	a;
	int	i;

	a = 0;
	while (mlx.map[a])
	{
		i = ft_int_strchr(MAPSET, mlx.map[a]);
		if (i == 1)
		{
			mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.iptr[3],
				mlx.x * 32, mlx.y * 32);
		}
		if (i >= 0 && i < 5)
			mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.iptr[i],
				mlx.x++ *32, mlx.y * 32);
		else if (i == 5)
		{
			mlx.xnb = mlx.x;
			mlx.x = 0;
			mlx.y++;
		}
		a++;
	}
	return (0);
}

static int	sl_hub_keypress(int key, t_prog *mlx)
{
	static int	movecount;
	int			p;

	p = sl_checkdest(key, &*mlx);
	if (p == 0)
		return (0);
	if (key == K_W || key == K_UP || key == K_A || key == K_LEFT
		|| key == K_S || key == K_DOWN || key == K_D || key == K_RIGHT)
	{
		mlx->map[p] = '0';
		if (key == K_W || key == K_UP)
			mlx->map[p - mlx->xnb - 1] = 'P';
		else if (key == K_A || key == K_LEFT)
			mlx->map[p - 1] = 'P';
		else if (key == K_S || key == K_DOWN)
			mlx->map[p + mlx->xnb + 1] = 'P';
		else if (key == K_D || key == K_RIGHT)
			mlx->map[p + 1] = 'P';
		printf("movecount : %d\n", ++movecount);
		mlx_clear_window(mlx->ptr, mlx->win);
		sl_display_map(*mlx);
	}
	if (key == K_ESC)
		sl_close_window(&*mlx);
	return (1);
}

void	sl_game_loop(t_prog *mlx)
{
	sl_display_map(*mlx);
	mlx_hook(mlx->win, 2, 0, sl_hub_keypress, &*mlx);
	mlx_hook(mlx->win, 17, 0, sl_close_window, &*mlx);
}
