/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 03:24:09 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/03 05:35:19 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_pile		*init_pile(void)
{
	t_pile	*pile;

	if (!(pile = (t_pile*)malloc(sizeof(t_pile))))
		return (NULL);
	pile->next = NULL;
	pile->line = NULL;
	pile->size = 0;
	return (pile);
}
