/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 03:33:56 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/06 09:13:05 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

static int	pile_up(int fd, t_pile *pile, char **str)
{
	int		ret;
	char	*line;
	int		pos;

	pos = -1;
	line = NULL;
	while ((ret = get_line(fd, &line, str)) > 0)
	{
		if (pars_build_line(pile, line))
			return (1);
		ft_strdel(&line);
	}
	if (ret == -1)
	{
		ft_putstr_fd("fdf: read error\n", 2);
		return (1);
	}
	return (0);
}

t_pile		*pars_map(char *str)
{
	int		fd;
	t_pile	*pile;
	char	*rest;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putstr_fd("fdf: can not open: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("' for reading\n", 2);
		return (NULL);
	}
	if (!(pile = init_pile()))
		return (NULL);
	rest = NULL;
	if (pile_up(fd, pile, &rest))
		return (NULL);
	if (rest)
		free(rest);
	return (pile);
}
