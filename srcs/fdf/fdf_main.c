/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:46:52 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/06 06:55:45 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void			fdf_init_data(t_env *env)
{
	int				i;

	i = -1;
	if (!(env->mat = (t_mat**)ft_memalloc(sizeof(t_mat*) * env->map.y)))
		error_manager(TMALLOC, env);
	if (!(env->mtmp = (t_mat**)ft_memalloc(sizeof(t_mat*) * env->map.y)))
		error_manager(TMALLOC, env);
	while (++i < env->map.y)
	{
		if (!(env->mat[i] = (t_mat*)ft_memalloc(sizeof(t_mat) * env->map.x)))
			error_manager(TMALLOC, env);
		if (!(env->mtmp[i] = (t_mat*)ft_memalloc(sizeof(t_mat) * env->map.x)))
			error_manager(TMALLOC, env);
	}
	i = -1;
	fdf_fill_mat(env);
	while (++i < env->map.y)
		ft_memdel((void**)&(env->map.map[i]));
}

int					fdf_main(t_env *env)
{
	env->mlx.mlx = mlx_init();
	env->mlx.image = mlx_new_image(env->mlx.mlx, SCREENX, SCREENY);
	env->mlx.id = mlx_new_window(env->mlx.mlx, SCREENX, SCREENY, "fdf");
	env->mlx.mem_image = (unsigned int*)mlx_get_data_addr(env->mlx.image,
			&env->mlx.pix, &env->mlx.size_line, &env->mlx.endian);
	fdf_init_data(env);
	fdf_mat_rotation(env);
	fdf_print(env, 0xFFFFFF);
	mlx_key_hook(env->mlx.id, fdf_handler, (void*)env);
	mlx_loop(env->mlx.mlx);
	return (1);
}
