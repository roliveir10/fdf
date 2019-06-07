/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 21:39:13 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/06 07:18:10 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <math.h>

static void			fdf_escap(t_env *env, int key)
{
	(void)key;
	fdf_delenv(env);
	exit(1);
}

static void			fdf_key_rotate(t_env *env, int key)
{
	static void		(*lst_function[3])(t_env*) = {fdf_fill_rotx,
		fdf_fill_roty, fdf_fill_rotz};
	static float	teta[3] = {M_PI / 45, M_PI / 45, M_PI / 45};

	fdf_print(env, 0x000000);
	env->rotation.teta[key / 2] += (key % 2 ? teta[key / 2] : -teta[key / 2]);
	lst_function[key / 2](env);
	fdf_mat_rotation(env);
	if (env->mode == MISO)
		fdf_iso(env, key);
}

static void			fdf_key_incrz(t_env *env, int key)
{
	fdf_print(env, 0x000000);
	if (key == 7 && env->rotation.incz <= 0.002)
		env->rotation.incz += 0.0001;
	else if (key == 6 && env->rotation.incz >= -0.002)
		env->rotation.incz -= 0.0001;
	fdf_mat_rotation(env);
	if (env->mode == MISO)
		fdf_iso(env, key);
}

int					fdf_handler(int key, void *param)
{
	static int		tkey[11] = {ESCAP, ROTXR, ROTXL, ROTYL, ROTYR, ROTZL, ROTZR,
		INCZ, DECZ, ISO, PARA};
	static void		(*lst_function[11])(t_env*, int) = {fdf_escap,
		fdf_key_rotate, fdf_key_rotate, fdf_key_rotate, fdf_key_rotate,
		fdf_key_rotate, fdf_key_rotate, fdf_key_incrz, fdf_key_incrz,
		fdf_iso, fdf_para};
	int				j;

	j = -1;
	while (++j < 11)
		if (tkey[j] == key)
		{
			lst_function[j]((t_env*)param, j - 1);
			fdf_print((t_env*)param, 0xFFFFFF);
		}
	return (0);
}
