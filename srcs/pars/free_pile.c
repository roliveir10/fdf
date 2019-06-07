/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:44:08 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/06 08:48:26 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void		free_pile(t_pile *pile)
{
	if (!pile)
		return ;
	free_pile(pile->next);
	pile->next = NULL;
	if (pile->line)
		free(pile->line);
	pile->line = NULL;
	free(pile);
}
