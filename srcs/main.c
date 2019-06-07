/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:33:06 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/06 09:39:08 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fdf_usage(int argc)
{
	if (argc < 2)
		ft_putendl_fd("usage: ./fdf <file>", 2);
	else
		return (1);
	return (0);
}

int				main(int argc, char **argv)
{
	t_env		env;

	if (!fdf_usage(argc))
		return (0);
	ft_bzero(&env, sizeof(t_env));
	if (pars_getmap(argc, argv, &env))
		return (1);
	fdf_main(&env);
	return (0);
}
