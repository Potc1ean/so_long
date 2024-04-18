/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_solve_problems.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:43:49 by ljohnson          #+#    #+#             */
/*   Updated: 2024/04/15 03:33:31 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sl_inc/so_long.h"

int	sl_solve_spmap(char **spmap)
{
	size_t	a;

	a = 0;
	while (spmap[a])
	{
		free(spmap[a]);
		a++;
	}
	free(spmap);
	return (0);
}

int	sl_solve_img(t_prog *mlx)
{
	size_t	a;

	a = 0;
	while (a <= 4)
	{
		mlx_destroy_image(mlx->ptr, mlx->iptr[a]);
		a++;
	}
	return (0);
}

int	sl_errhub(int pcount, int ecount, int ccount)
{
	if (pcount < 1)
		return (sl_err1(8));
	if (pcount > 1)
		return (sl_err2(16));
	if (ecount < 1)
		return (sl_err1(7));
	if (ccount < 1)
		return (sl_err2(13));
	return (0);
}

int	sl_err1(int nb)
{
	if (nb == 1)
		return (0 * printf("Error 1 : Need only one <map.ber> as argument !\n"));
	else if (nb == 2)
		return (0 * printf("Error 2 : The map is not playable !\n"));
	else if (nb == 3)
		return (0 * printf("Error 3 : The map is not closed on top !\n"));
	else if (nb == 4)
		return (0 * printf("Error 4 : The map is not closed on side !\n"));
	else if (nb == 5)
		return (0 * printf("Error 5 : The map is not rectangular !\n"));
	else if (nb == 6)
		return (0 * printf("Error 6 : The map is not closed on bottom !\n"));
	else if (nb == 7)
		return (0 * printf("Error 7 : There is no Exit on the map !\n"));
	else if (nb == 8)
		return (0 * printf("Error 8 : There is no Spawn on the map !\n"));
	else if (nb == 9)
		return (0 * printf("the player can't move up !\n"));
	else if (nb == 10)
		return (0 * printf("the player can't move left !\n"));
	else if (nb == 11)
		return (0 * printf("the player can't move down !\n"));
	else if (nb == 12)
		return (0 * printf("the player can't move right !\n"));
	return (0);
}

int	sl_err2(int nb)
{
	if (nb == 13)
		return (0 * printf("Error 13 : There is no collectible on the map !\n"));
	else if (nb == 14)
		return (0 * printf("Error 14 : The map is not rectangular !\n"));
	else if (nb == 15)
		return (0 * printf("Error 15 : There is an ovni in the map !\n"));
	else if (nb == 16)
		return (0 * printf("Error 16 : You need only one spawn on the map !\n"));
	else if (nb == 17)
		return (0 * printf("You can't leave without all collectible, "));
	else if (nb == 18)
		return (0 * printf("There is a wall here, "));
	else if (nb == 19)
		return (0 * printf("The game is closed, goodbye friend !\n"));
	else if (nb == 20)
		return (0 * printf("Error 20 : This is not a valid map !\n"));
	return (0);
}
