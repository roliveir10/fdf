/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:17:19 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/06 09:54:45 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void				fdf_fill_rotx(t_env *env)
{
	env->rotation.mat[0][0][0] = 1;
	env->rotation.mat[0][1][1] = cos(env->rotation.teta[0]);
	env->rotation.mat[0][1][2] = -sin(env->rotation.teta[0]);
	env->rotation.mat[0][2][1] = sin(env->rotation.teta[0]);
	env->rotation.mat[0][2][2] = cos(env->rotation.teta[0]);
}

void				fdf_fill_roty(t_env *env)
{
	env->rotation.mat[1][0][0] = cos(env->rotation.teta[1]);
	env->rotation.mat[1][0][2] = sin(env->rotation.teta[1]);
	env->rotation.mat[1][1][1] = 1;
	env->rotation.mat[1][2][0] = -sin(env->rotation.teta[1]);
	env->rotation.mat[1][2][2] = cos(env->rotation.teta[1]);
}

void				fdf_fill_rotz(t_env *env)
{
	env->rotation.mat[2][0][0] = cos(env->rotation.teta[2]);
	env->rotation.mat[2][0][1] = -sin(env->rotation.teta[2]);
	env->rotation.mat[2][1][0] = sin(env->rotation.teta[2]);
	env->rotation.mat[2][1][1] = cos(env->rotation.teta[2]);
	env->rotation.mat[2][2][2] = 1;
}

static void			fdf_fill_isomat(t_env *env)
{
	env->iso[0][0] = sqrt(2) / 2;
	env->iso[0][1] = -sqrt(2) / 2;
	env->iso[1][0] = -1 / sqrt(6);
	env->iso[1][1] = env->iso[1][0];
	env->iso[1][2] = sqrt(2 / 3);
}

void				fdf_fill_mat(t_env *env)
{
	int				i;
	int				j;

	i = -1;
	while (++i < env->map.y)
	{
		j = -1;
		while (++j < env->map.x)
		{
			env->mat[i][j].x = (2 * j + 1 - env->map.x) * env->pixperpts / 2;
			env->mtmp[i][j].x = (2 * j + 1 - env->map.x) * env->pixperpts / 2;
			env->mat[i][j].y = (-2 * i - 1 + env->map.y) * env->pixperpts / 2;
			env->mtmp[i][j].y = (-2 * i - 1 + env->map.y) * env->pixperpts / 2;
			env->mat[i][j].z = env->map.map[i][j] * env->pixperpts;
			env->mtmp[i][j].z = env->map.map[i][j] * env->pixperpts;
		}
	}
	env->rotation.teta[0] = 3;
	env->rotation.teta[2] = 0.2;
	fdf_fill_rotx(env);
	fdf_fill_roty(env);
	fdf_fill_rotz(env);
	fdf_fill_isomat(env);
	env->rotation.incz = 0.001;
}
