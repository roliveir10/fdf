/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_build_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 03:44:50 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/06 09:31:36 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>

int		nbr_atoi(char *str)
{
	int	k;
	int	sum;

	k = 0;
	sum = 0;
	while (str[k])
	{
		if (str[k] == '-' || str[k] == '+')
			k++;
		while (ft_isdigit(str[k]))
			k++;
		if (str[k] && !(str[k] == ' ' || str[k] == '\n'))
			return (-1);
		if (k)
			sum++;
		while (str[k] == ' ')
			k++;
	}
	return (sum);
}

int		fill_element(t_pile *pile, char *str)
{
	int	j;
	int	index;
	int	err;

	j = -1;
	index = 0;
	err = 0;
	while (str[index] && ++j < pile->size)
	{
		pile->line[j] = ft_atoip_err(str, &index, &err);
		if (err == 1)
		{
			ft_putstr_fd("fdf: at least one element does not fit in int\n", 2);
			return (1);
		}
	}
	return (0);
}

int		pars_build_line(t_pile *og_pile, char *str)
{
	t_pile	*pile;

	pile = og_pile;
	while (pile && pile->next)
		pile = pile->next;
	if (!(pile->next = init_pile()))
		return (1);
	pile = pile->next;
	if ((pile->size = nbr_atoi(str)) == -1)
	{
		ft_putstr_fd("fdf: wrong file format\n", 2);
		return (1);
	}
	if (!(pile->line = (int*)malloc(sizeof(int) * pile->size)))
		return (1);
	return (fill_element(pile, str));
}
