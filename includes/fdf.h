/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:35:32 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/06 09:56:10 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include "libft.h"

# define SCREENX 1000
# define SCREENY 1000
# define BUFF_PARS 4096

typedef enum			e_err
{
	TMALLOC
}						t_err;

typedef struct			s_map
{
	short				**map;
	int					x;
	int					y;
}						t_map;

typedef struct			s_mat
{
	int					x;
	int					y;
	int					z;
}						t_mat;

typedef struct			s_rotation
{
	float				mat[3][3][3];
	float				teta[3];
	float				incz;
}						t_rotation;

typedef struct			s_calc
{
	int					dx;
	int					dy;
	int					e;
	t_mat				ma;
	t_mat				mb;
}						t_calc;

typedef enum			e_vector
{
	UR,
	DR,
	UL,
	DL,
	HORL,
	HORR,
	VERU,
	VERD
}						t_vector;

typedef enum			e_key
{
	ESCAP = 53,
	ROTXL = 115,
	ROTXR = 119,
	ROTYL = 117,
	ROTYR = 121,
	ROTZL = 279,
	ROTZR = 116,
	INCZ = 71,
	DECZ = 81,
	ISO = 34,
	PARA = 45
}						t_key;

typedef enum			e_mode
{
	MPARA,
	MISO
}						t_mode;

typedef struct			s_mlx
{
	void				*mlx;
	void				*image;
	void				*id;
	unsigned int		*mem_image;
	int					pix;
	int					size_line;
	int					endian;
}						t_mlx;

typedef struct			s_env
{
	t_mlx				mlx;
	void				*image;
	void				*id;
	int					pixperpts;
	t_map				map;
	t_mat				**mat;
	t_mat				**mtmp;
	t_rotation			rotation;
	int					mode;
	float				iso[2][3];
}						t_env;

typedef struct			s_pile
{
	int					*line;
	int					size;
	struct s_pile		*next;
}						t_pile;

int						fdf_main(t_env *env);
int						fdf_handler(int key, void *param);
void					fdf_mat_rotation(t_env *env);
void					fdf_mat_iso(t_env *env);

/*
**	fill
*/

void					fdf_fill_mat(t_env *env);
void					fdf_fill_rotx(t_env *env);
void					fdf_fill_roty(t_env *env);
void					fdf_fill_rotz(t_env *env);

/*
**	parsing
*/

int						pars_getmap(int argc, char **argv, t_env *env);
t_pile					*pars_map(char *name);
t_pile					*init_pile(void);
int						pars_build_line(t_pile *pile, char *str);
int						ft_atoip_err(const char *str, int *i, int *err);
int						pars_max_min(t_pile *pile, int *max, int *min);
void					pars_normal(t_pile *pile, int ext, t_env *env);
void					free_pile(t_pile *pile);

/*
**	alloc
*/

void					fdf_alloc_mat(t_env *env);
void					fdf_delenv(t_env *env);

/*
**	error
*/

void					error_manager(t_err err, t_env *env);

/*
**	print
*/

void					fdf_print(t_env *env, int color);
void					fdf_print_center(t_env *env, int x, int y, int color);
void					fdf_print_up(t_env *env, t_calc *calc, int color,
		int side);
void					fdf_print_do(t_env *env, t_calc *calc, int color,
		int side);
void					fdf_print_horr(t_env *env, t_calc *calc, int color,
		int side);
void					fdf_print_horl(t_env *env, t_calc *calc, int color,
		int side);
void					fdf_print_veru(t_env *env, t_calc *calc, int color,
		int side);
void					fdf_print_verl(t_env *env, t_calc *calc, int color,
		int side);

/*
**	mode
*/

void					fdf_iso(t_env *env, int key);
void					fdf_para(t_env *env, int key);
#endif
