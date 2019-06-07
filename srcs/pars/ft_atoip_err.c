/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoip_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 05:21:15 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/04 05:54:13 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			check_next_step(int nbr, int next_digit)
{
	if (nbr > 214748364 || (nbr == 214748364 && next_digit > 7))
		return (1);
	if (nbr < -214748364 || (nbr == -214748364 && next_digit > 8))
		return (1);
	return (0);
}

int					ft_atoip_err(const char *str, int *i, int *err)
{
	unsigned char	*mstr;
	int				is_neg;
	int				final;

	mstr = (unsigned char*)str;
	final = 0;
	is_neg = 1;
	while ((mstr[*i] >= 9 && mstr[*i] <= 13) || mstr[*i] == 32)
		(*i)++;
	if (mstr[*i] == '-')
		is_neg = -1;
	if (mstr[*i] == '-' || mstr[*i] == '+')
		(*i)++;
	while (mstr[*i] >= '0' && mstr[*i] <= '9')
	{
		if (check_next_step(final, mstr[*i] - '0'))
		{
			*err = 1;
			return (0);
		}
		final *= 10;
		final += (mstr[*i] - '0');
		(*i)++;
	}
	return (is_neg * final);
}
