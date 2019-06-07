/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 02:05:25 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/04 02:11:54 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				fdf_iso(t_env *env, int key)
{
	if (key == 8 && env->mode == MISO)
		return ;
	fdf_print(env, 0x000000);
	env->mode = MISO;
	fdf_mat_iso(env);
}

void				fdf_para(t_env *env, int key)
{
	if (key == 9 && env->mode == MPARA)
		return ;
	fdf_print(env, 0x000000);
	env->mode = MPARA;
	fdf_mat_rotation(env);
}
