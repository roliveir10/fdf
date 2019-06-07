/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mat_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 21:51:40 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/04 05:08:31 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_mat_calc_rotation(t_mat *mtmp, t_mat mat, float rot[3][3],
		float rotz)
{
	mtmp->x = rot[0][0] * mat.x + rot[0][1] * mat.y + rot[0][2] * mat.z * rotz;
	mtmp->y = rot[1][0] * mat.x + rot[1][1] * mat.y + rot[1][2] * mat.z * rotz;
	mtmp->z = rot[2][0] * mat.x + rot[2][1] * mat.y + rot[2][2] * mat.z * rotz;
}

static void		fdf_mat_calc_iso(t_mat *mtmp, t_mat mat, float iso[2][3])
{
	mtmp->x = iso[0][0] * mat.x + iso[0][1] * mat.y + iso[0][2] * mat.z;
	mtmp->y = iso[1][0] * mat.x + iso[1][1] * mat.y + iso[1][2] * mat.z;
}

void			fdf_mat_rotation(t_env *env)
{
	int			i;
	int			j;
	int			k;

	i = -1;
	while (++i < env->map.y)
	{
		j = -1;
		while (++j < env->map.x)
		{
			k = -1;
			while (++k < 3)
			{
				if (!k)
					fdf_mat_calc_rotation(&(env->mtmp[i][j]), env->mat[i][j],
							env->rotation.mat[k], env->rotation.incz);
				else
					fdf_mat_calc_rotation(&(env->mtmp[i][j]),
							env->mtmp[i][j], env->rotation.mat[k], 1);
			}
		}
	}
}

void			fdf_mat_iso(t_env *env)
{
	int			i;
	int			j;

	i = -1;
	while (++i < env->map.y)
	{
		j = -1;
		while (++j < env->map.x)
			fdf_mat_calc_iso(&(env->mtmp[i][j]), env->mtmp[i][j], env->iso);
	}
}
