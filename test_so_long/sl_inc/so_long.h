/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:06:03 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/14 09:08:46 by ljohnson         ###   ########lyon.fr   */
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

// s_program struct for program, map and vars infos
// = mlx

/*
void	*ptr = mlx init pointer (mlx_init)
void	*win = window pointer (mlx_new_window)
void	*iptr[5] = xpm file image pointer (mlx_xpm_file_to_image)
char	*ipath[5] = path of the xpm file
int		iwidth[5] = width of the xpm file (mlx_xpm_file_to_image)
int		iwidth[5] = height of the xpm file (mlx_xpm_file_to_image)
char	*map = map string
int		xnb = line size
int		ynb = number of line
int		x = coordinate
int		y = coordinate
char	*stock = get_next_line output for map
int		fd = file descriptor of the map for GNL
*/

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
	char	*stock;
	int		fd;
}	t_prog;

// s_vstock struct for init_map functions
// = vars

/*
char	*temp = here just to free GNL output correctly
int		pcount = char 'P' count on map (need only 1)
int		ecount = char 'E' count on map (need at least 1)
int		ccount = char 'C' count on map (need at least 1)
*/

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

#endif