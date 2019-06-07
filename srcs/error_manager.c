/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 00:43:03 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/04 05:58:25 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

void			fdf_delenv(t_env *env)
{
	int			i;

	i = -1;
	while (++i < env->map.y)
		ft_memdel((void**)&(env->map.map[i]));
	i = -1;
	if (env->mat)
	{
		while (++i < env->map.y)
			ft_memdel((void**)&(env->mat[i]));
		ft_memdel((void**)&(env->mat));
	}
	i = -1;
	if (env->mtmp)
	{
		while (++i < env->map.y)
			ft_memdel((void**)&(env->mtmp[i]));
		ft_memdel((void**)&(env->mtmp));
	}
	mlx_destroy_image(env->mlx.mlx, env->mlx.image);
}

void			error_manager(t_err err, t_env *env)
{
	ft_putstr_fd("fdf: error ID=", 2);
	ft_putnbr_fd(err, 2);
	ft_putendl_fd(" exiting", 2);
	fdf_delenv(env);
	exit(err);
}
