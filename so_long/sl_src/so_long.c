/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 05:28:12 by ichpakov          #+#    #+#             */
/*   Updated: 2024/05/15 17:11:48 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sl_inc/so_long.h"

static int	sl_check_wall_error(char *mapstock)
{
	char	**spmap;
	size_t	a;
	size_t	slen;

	spmap = ft_split(mapstock, '\n');
	slen = ft_strlen(spmap[0]);
	a = 0;
	if (ft_isnotcharset('1', spmap[0]))
		return (sl_solve_spmap(spmap) * sl_err1(3));
	while (spmap[a])
	{
		if (ft_strlen(spmap[a]) != slen)
			return (sl_solve_spmap(spmap) * sl_err2(14));
		if (spmap[a][slen - 1] != '1' || spmap[a][0] != '1')
			return (sl_solve_spmap(spmap) * sl_err1(4));
		a++;
	}
	if (ft_isnotcharset('1', spmap[a - 1]))
		return (sl_solve_spmap(spmap) * sl_err1(6));
	sl_solve_spmap(spmap);
	return (1);
}

static int	sl_check_map_error(t_prog *mlx, t_vstock *vars)
{
	int	a;

	a = 0;
	vars->pcount = 0;
	vars->ecount = 0;
	vars->ccount = 0;
	while (mlx->map[a++])
	{
		if (ft_int_strchr(MAPSET, mlx->map[a]) == -1)
			return (sl_err2(15));
		if (mlx->map[a] == 'P')
			vars->pcount++;
		if (mlx->map[a] == 'E')
			vars->ecount++;
		if (mlx->map[a] == 'C')
			vars->ccount++;
		if (mlx->map[a] == '\n' || mlx->map[a] == '\0')
			mlx->ynb++;
	}
	if (!sl_check_wall_error(mlx->map) || vars->pcount != 1
		|| vars->ecount != 1 || vars->ccount < 1)
		return (sl_errhub(vars->pcount, vars->ecount, vars->ccount));
	mlx->xnb = ft_int_strchr(mlx->map, '\n');
	return (1);
}

static char	*sl_init_map(char *av, t_prog *mlx)
{
	t_vstock	vars;

	mlx->map = NULL;
	mlx->stock = NULL;
	vars.temp = NULL;
	mlx->fd = open(av, O_RDONLY);
	if (mlx->fd < 0)
	{
		sl_err2(20);
		return (NULL);
	}
	mlx->map = sl_build_map(mlx, &vars);
	close (mlx->fd);
	if (!mlx->map)
		return (NULL);
	if ((!sl_check_map_error(mlx, &vars))
		|| (sl_floodfile(*mlx, &vars) == -1))
	{
		free (mlx->map);
		return (NULL);
	}
	return (mlx->map);
}

static void	sl_init_img(t_prog *mlx)
{
	size_t	a;

	a = 0;
	mlx->ipath[0] = "sl_xpm/collectible.xpm";
	mlx->ipath[1] = "sl_xpm/player.xpm";
	mlx->ipath[2] = "sl_xpm/exit.xpm";
	mlx->ipath[3] = "sl_xpm/floor.xpm";
	mlx->ipath[4] = "sl_xpm/wall.xpm";
	while (a <= 4)
	{
		mlx->iptr[a] = mlx_xpm_file_to_image(mlx->ptr, mlx->ipath[a],
				&mlx->iwidth[a], &mlx->iheight[a]);
		a++;
	}
}

int	main(int ac, char **av)
{
	t_prog	mlx;

	if (ac != 2)
		return (sl_err1(1));
	mlx.map = sl_init_map(av[1], &mlx);
	if (!mlx.map)
		return (sl_err1(2));
	mlx.ptr = mlx_init();
	sl_init_img(&mlx);
	mlx.win = mlx_new_window(mlx.ptr, mlx.xnb * 32, mlx.ynb * 32, "so_long");
	sl_game_loop(&mlx);
	mlx.iloop = mlx_loop(mlx.ptr);
	return (0);
}
