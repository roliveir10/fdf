/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_diagup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 02:27:49 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/04 02:54:43 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_print_ura(t_env *env, t_calc *calc, int color)
{
	calc->e = calc->dx;
	calc->dx *= 2;
	calc->dy *= 2;
	while (1)
	{
		fdf_print_center(env, calc->ma.x, calc->ma.y, color);
		if ((++calc->ma.x) == calc->mb.x)
			break ;
		if ((calc->e -= calc->dy) < 0)
		{
			calc->ma.y++;
			calc->e += calc->dx;
		}
	}
}

static void		fdf_print_urb(t_env *env, t_calc *calc, int color)
{
	calc->e = calc->dy;
	calc->dy *= 2;
	calc->dx *= 2;
	while (1)
	{
		fdf_print_center(env, calc->ma.x, calc->ma.y, color);
		if ((++calc->ma.y) == calc->mb.y)
			break ;
		if ((calc->e -= calc->dx) < 0)
		{
			calc->ma.x++;
			calc->e += calc->dy;
		}
	}
}

static void		fdf_print_ula(t_env *env, t_calc *calc, int color)
{
	calc->e = calc->dx;
	calc->dx *= 2;
	calc->dy *= 2;
	while (1)
	{
		fdf_print_center(env, calc->ma.x, calc->ma.y, color);
		if ((--calc->ma.x) == calc->mb.x)
			break ;
		if ((calc->e += calc->dy) >= 0)
		{
			calc->ma.y++;
			calc->e += calc->dx;
		}
	}
}

static void		fdf_print_ulb(t_env *env, t_calc *calc, int color)
{
	calc->e = calc->dy;
	calc->dy *= 2;
	calc->dx *= 2;
	while (1)
	{
		fdf_print_center(env, calc->ma.x, calc->ma.y, color);
		if ((++calc->ma.y) == calc->mb.y)
			break ;
		if ((calc->e += calc->dx) <= 0)
		{
			calc->ma.x--;
			calc->e += calc->dy;
		}
	}
}

void			fdf_print_up(t_env *env, t_calc *calc, int color, int side)
{
	if (side == UR)
	{
		if (calc->dx >= calc->dy)
			fdf_print_ura(env, calc, color);
		else
			fdf_print_urb(env, calc, color);
	}
	else
	{
		if (-calc->dx >= calc->dy)
			fdf_print_ula(env, calc, color);
		else
			fdf_print_ulb(env, calc, color);
	}
}
