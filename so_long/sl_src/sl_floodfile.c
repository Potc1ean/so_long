/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_floodfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:04:13 by ichpakov          #+#    #+#             */
/*   Updated: 2024/05/15 16:54:34 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sl_inc/so_long.h"

static	void	p_pos(int *x, int *y, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				*y = j;
				*x = i;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

static	int	checker(int y, int x, t_prog mlx, t_vstock *vars)
{
	int		a;

	a = 0;
	if (y >= mlx.ynb || x >= mlx.xnb || y < 0 || x < 0
		|| mlx.m_tmp[y][x] == '1' || mlx.m_tmp[y][x] == '2')
		return (0);
	else if (mlx.m_tmp[y][x] == 'C')
		vars->itmp++;
	else if (mlx.m_tmp[y][x] == 'E')
		return (1);
	mlx.m_tmp[y][x] = '2';
	a += checker(y + 1, x, mlx, vars);
	a += checker(y - 1, x, mlx, vars);
	a += checker(y, x + 1, mlx, vars);
	a += checker(y, x - 1, mlx, vars);
	return (a);
}

int	sl_floodfile(t_prog mlx, t_vstock *vars)
{
	int		r;
	int		rtn;

	r = 0;
	rtn = 0;
	vars->itmp = 0;
	mlx.m_tmp = ft_split(mlx.map, '\n');
	p_pos(&mlx.x, &mlx.y, mlx.m_tmp);
	r = checker(mlx.y, mlx.x, mlx, vars);
	if (r < 1)
		rtn = -1;
	if (vars->itmp != vars->ccount)
		rtn = -1;
	sl_solve_spmap(mlx.m_tmp);
	return (rtn);
}
