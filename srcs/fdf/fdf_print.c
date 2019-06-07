/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 23:19:43 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/04 06:22:27 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static int			fdf_find_vector(t_calc calc)
{
	if (calc.dx > 0 && calc.dy > 0)
		return (UR);
	else if (calc.dx > 0 && calc.dy < 0)
		return (DR);
	else if (calc.dx < 0 && calc.dy > 0)
		return (UL);
	else if (calc.dx < 0 && calc.dy < 0)
		return (DL);
	else if (calc.dx > 0 && !calc.dy)
		return (HORL);
	else if (calc.dx < 0 && !calc.dy)
		return (HORR);
	else if (!calc.dx && calc.dy > 0)
		return (VERU);
	else if (!calc.dx && calc.dy < 0)
		return (VERD);
	return (-1);
}

static void			fdf_print_line(t_env *env, t_mat mat_a,
		t_mat mat_b, int color)
{
	t_calc			calc;
	int				vector;
	static void		(*lst_function[8])(t_env*, t_calc*, int, int) = {
		fdf_print_up, fdf_print_do, fdf_print_up, fdf_print_do,
		fdf_print_horr, fdf_print_horl, fdf_print_veru, fdf_print_verl};

	ft_bzero(&calc, sizeof(t_calc));
	calc.dx = mat_b.x - mat_a.x;
	calc.dy = mat_b.y - mat_a.y;
	calc.ma = mat_a;
	calc.mb = mat_b;
	if ((vector = fdf_find_vector(calc)) != -1)
		lst_function[vector](env, &calc, color, vector);
}

void				fdf_print_center(t_env *env, int x, int y, int color)
{
	if (y > -SCREENY / 2 && y < SCREENY / 2 && x > -SCREENX / 2
			&& x < SCREENX / 2)
		env->mlx.mem_image[(y + SCREENY / 2) * (env->mlx.size_line / 4)
			+ x + SCREENX / 2] = color;
}

void				fdf_print(t_env *env, int color)
{
	int				i;
	int				j;

	i = -1;
	while (++i < env->map.y)
	{
		j = -1;
		while (++j < env->map.x)
		{
			if (j + 1 < env->map.x)
				fdf_print_line(env, env->mtmp[i][j], env->mtmp[i][j + 1],
						color);
			if (i + 1 < env->map.y)
				fdf_print_line(env, env->mtmp[i][j], env->mtmp[i + 1][j],
						color);
		}
	}
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.id, env->mlx.image, 0, 0);
}
