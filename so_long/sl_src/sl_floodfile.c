/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_floodfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:04:13 by ichpakov          #+#    #+#             */
/*   Updated: 2024/04/24 22:52:33 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sl_inc/so_long.h"

int		sl_road_checker(int y, int x, t_prog *mlx, char **map)
{
    int		a;
    
    a = 0;
    if (y >= mlx->ynb || x >= mlx->xnb || y < 0 || x < 0
        || map[y][x] == '1' || map[y][x] == '2')
        return (0);
        
    else if (map[y][x] == 'E')
        return (1);
    else if (map[y][x] == 'C')
        mlx->rubis++;
    map[y][x] = '2';
    a += sl_road_checker(y + 1, x, mlx, map);
    a += sl_road_checker(y - 1, x, mlx, map);
    a += sl_road_checker(y, x + 1, mlx, map);
    a += sl_road_checker(y, x - 1, mlx, map);
    
    return (a);
}

int		floodfile(char **map, t_prog *mlx)
{
	int i;
	int j;
	int rubis;
	char **map;
	
	i = 0;
	j = 0;
	rubis = 0;
	map = ft_split(mlx->map, '\n');
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				break;
			j++;
		}
		j = 0;
		i++;
	}
	sl_road_checker(i, j, &rubis, mlx, map);
	sl_solve_spmap(map);
}


go faire une struct qui a toutes les coordonnes des trucs dont on doit avoir l'access,puis on fait 
une recurssive depuis le perso pour chaque coordonnees
