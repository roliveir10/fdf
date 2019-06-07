/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 00:24:49 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/06 09:54:17 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int				pars_size_pile(t_pile *pile)
{
	t_pile		*tmp;
	int			size;

	tmp = pile;
	size = 0;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

int				pars_check_size(t_pile *pile)
{
	int			size;
	t_pile		*tmp;
	int			nbr;

	nbr = 1;
	tmp = pile->next;
	if (!(size = tmp->size))
	{
		ft_putstr_fd("fdf: first line is empty\n", 2);
		return (1);
	}
	while ((tmp = tmp->next))
	{
		nbr++;
		if (tmp->size != size)
		{
			ft_putstr_fd("fdf: line ", 2);
			ft_putnbr_fd(nbr, 2);
			ft_putstr_fd(" is not well formated\n", 2);
			return (1);
		}
	}
	return (0);
}

/*
**	need to set env->map.x (int) && env->map.y (int)
**	need to set env->map.map (short**)
** 	need to set env->pixperpt (nombre de pixel pour 1 ecart,
**		taille de la fenetre definie dans fdf.h)
**	if error 0 is return else 1
**	if error, call error_manager(ERR, env);
*/

int				fill_mat(t_env *env, t_pile *pile)
{
	int			max;
	int			min;
	int			ext;

	pars_max_min(pile->next, &max, &min);
	if (max == min && min == 0)
		return (0);
	if (ft_abs(max) > ft_abs(min))
		ext = ft_abs(max);
	else
		ext = ft_abs(min);
	pars_normal(pile->next, ext, env);
	free_pile(pile);
	pile = NULL;
	return (0);
}

int				pars_getmap(int argc, char **argv, t_env *env)
{
	t_pile		*pile;

	(void)argc;
	if (!(pile = pars_map(argv[1])))
		return (1);
	if (!pile || !pile->next)
	{
		ft_putstr_fd("fdf: file is empty\n", 2);
		return (1);
	}
	env->map.y = pars_size_pile(pile);
	env->map.x = pile->next->size;
	if (pars_check_size(pile))
		return (1);
	env->pixperpts = (int)((SCREENX / env->map.x) / 1.2);
	env->map.map = (short**)malloc(sizeof(short*) * env->map.y);
	fill_mat(env, pile);
	return (0);
}
