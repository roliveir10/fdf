/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 05:46:51 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/06 09:25:27 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

static short	*ft_expand(int ext, int *line, int size)
{
	int			j;
	short		*norm;
	long long	tmp;

	(void)ext;
	if (!(norm = (short*)malloc(sizeof(short) * size)))
		return (NULL);
	j = -1;
	while (++j < size)
	{
		tmp = ((long long)line[j] * size * 1000) / (4 * ext);
		norm[j] = tmp;
	}
	return (norm);
}

void			pars_normal(t_pile *pile, int ext, t_env *env)
{
	int			i;
	t_pile		*tmp;

	tmp = pile;
	i = -1;
	while (++i < env->map.y)
	{
		env->map.map[i] = ft_expand(ext, tmp->line, env->map.x);
		tmp = tmp->next;
	}
}
