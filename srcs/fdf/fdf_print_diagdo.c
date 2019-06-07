/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_diagdo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 02:41:19 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/04 03:50:31 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_print_dra(t_env *env, t_calc *calc, int color)
{
	calc->e = calc->dx;
	calc->dx *= 2;
	calc->dy *= 2;
	while (1)
	{
		fdf_print_center(env, calc->ma.x, calc->ma.y, color);
		if ((++calc->ma.x) == calc->mb.x)
			break ;
		if ((calc->e += calc->dy) < 0)
		{
			calc->ma.y--;
			calc->e += calc->dx;
		}
	}
}

static void		fdf_print_drb(t_env *env, t_calc *calc, int color)
{
	calc->e = calc->dy;
	calc->dy *= 2;
	calc->dx *= 2;
	while (1)
	{
		fdf_print_center(env, calc->ma.x, calc->ma.y, color);
		if ((--calc->ma.y) == calc->mb.y)
			break ;
		if ((calc->e += calc->dx) > 0)
		{
			calc->ma.x++;
			calc->e += calc->dy;
		}
	}
}

static void		fdf_print_dla(t_env *env, t_calc *calc, int color)
{
	calc->e = calc->dx;
	calc->dx *= 2;
	calc->dy *= 2;
	while (1)
	{
		fdf_print_center(env, calc->ma.x, calc->ma.y, color);
		if ((--calc->ma.x) == calc->mb.x)
			break ;
		if ((calc->e -= calc->dy) >= 0)
		{
			calc->ma.y--;
			calc->e += calc->dx;
		}
	}
}

static void		fdf_print_dlb(t_env *env, t_calc *calc, int color)
{
	calc->e = calc->dy;
	calc->dy *= 2;
	calc->dx *= 2;
	while (1)
	{
		fdf_print_center(env, calc->ma.x, calc->ma.y, color);
		if ((--calc->ma.y) == calc->mb.y)
			break ;
		if ((calc->e -= calc->dx) >= 0)
		{
			calc->ma.x--;
			calc->e += calc->dy;
		}
	}
}

void			fdf_print_do(t_env *env, t_calc *calc, int color, int side)
{
	if (side == DR)
	{
		if (calc->dx >= -calc->dy)
			fdf_print_dra(env, calc, color);
		else
			fdf_print_drb(env, calc, color);
	}
	else
	{
		if (calc->dx <= calc->dy)
			fdf_print_dla(env, calc, color);
		else
			fdf_print_dlb(env, calc, color);
	}
}
