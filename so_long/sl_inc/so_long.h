/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 03:24:01 by ichpakov          #+#    #+#             */
/*   Updated: 2024/04/24 22:39:04 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../mlx/mlx.h"
# include "../libft/lib_includes/libft.h"
# include "sl_keys.h"

# define MAPSET "CPE01\n"

/*/////////////////////////////////////////////////////////////////////////////
		STRUCTURES TYPEDEFS
*//////////////////////////////////////////////////////////////////////////////

typedef struct s_program
{
	void	*ptr;
	void	*win;
	int		iloop;
	void	*iptr[5];
	char	*ipath[5];
	int		iwidth[5];
	int		iheight[5];
	char	*map;
	int		xnb;
	int		ynb;
	int		x;
	int		y;
	int		rubis;
	char	*stock;
	int		fd;
}	t_prog;

typedef struct s_vstock
{
	char	*temp;
	int		pcount;
	int		ecount;
	int		ccount;
}	t_vstock;

/*/////////////////////////////////////////////////////////////////////////////
		FUNCTIONS PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

// sl_utils.c

char	*sl_build_map(t_prog *mlx, t_vstock *vars);
int		sl_check_tile(t_prog *mlx, char tile);

// sl_game_loop.c

void	sl_game_loop(t_prog *mlx);
int		sl_close_window(t_prog *mlx);

// sl_solve_problems.c

int		sl_solve_spmap(char **spmap);
int		sl_solve_img(t_prog *mlx);
int		sl_errhub(int pcount, int ecount, int ccount);
int		sl_err1(int nb);
int		sl_err2(int nb);

// sl_floodfile.c

int    sl_floodfile(int y, int x,int item ,t_prog *mlx);

#endif