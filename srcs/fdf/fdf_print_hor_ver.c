/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_hor_ver.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 18:05:16 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/04 02:49:03 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fdf_print_horr(t_env *env, t_calc *calc, int color, int side)
{
	(void)side;
	fdf_print_center(env, calc->ma.x, calc->ma.y, color);
	while ((calc->ma.x++ != calc->mb.x))
		fdf_print_center(env, calc->ma.x, calc->ma.y, color);
}

void			fdf_print_horl(t_env *env, t_calc *calc, int color, int side)
{
	(void)side;
	fdf_print_center(env, calc->ma.x, calc->ma.y, color);
	while ((calc->ma.x-- != calc->mb.x))
		fdf_print_center(env, calc->ma.x, calc->ma.y, color);
}

void			fdf_print_veru(t_env *env, t_calc *calc, int color, int side)
{
	(void)side;
	fdf_print_center(env, calc->ma.x, calc->ma.y, color);
	while ((calc->ma.y++ != calc->mb.y))
		fdf_print_center(env, calc->ma.x, calc->ma.y, color);
}

void			fdf_print_verl(t_env *env, t_calc *calc, int color, int side)
{
	(void)side;
	fdf_print_center(env, calc->ma.x, calc->ma.y, color);
	while ((calc->ma.y-- != calc->mb.y))
		fdf_print_center(env, calc->ma.x, calc->ma.y, color);
}
