/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 06:14:00 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/06 09:32:16 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			pars_max_min(t_pile *pile, int *max, int *min)
{
	t_pile	*tmp;
	int		k;

	tmp = pile;
	if (tmp && tmp->line)
	{
		*max = tmp->line[0];
		*min = tmp->line[0];
	}
	while (tmp)
	{
		k = 0;
		while (tmp->size && k < tmp->size)
		{
			if (tmp->line[k] > *max)
				*max = tmp->line[k];
			if (tmp->line[k] < *min)
				*min = tmp->line[k];
			k++;
		}
		tmp = tmp->next;
	}
	return (0);
}
