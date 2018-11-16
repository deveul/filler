/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:13:46 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/16 10:46:53 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_allocate_map(t_filler *f, char *line)
{
	int		cpt;
	int		i;

	i = 0;
	cpt = 8;
	if (!ft_strstr(line, "Plateau"))
	{
		ft_strdel(&line);
		return (-1);
	}
	if (!line[cpt])
	{
		ft_strdel(&line);
		return (-1);
	}
	f->l = ft_atoi(line + cpt);
	while (line[cpt] && ft_isdigit(line[cpt]))
		cpt++;
	if (!line[cpt])
	{
		ft_strdel(&line);
		return (-1);
	}
	while (line[cpt] && !ft_isdigit(line[cpt]))
		cpt++;
	if (!line[cpt])
	{
		ft_strdel(&line);
		return (-1);
	}
	f->c = ft_atoi(line + (cpt));
	if (f->c == 0 || f->l == 0)
		return (-1);
	if (!(f->maps = ft_memalloc(sizeof(int*) * f->l)))
		return (-1);
	while (i < f->l)
	{
		if (!(f->maps[i] = ft_memalloc(sizeof(int) * f->c)))
			return (-1);
		i++;
	}
	ft_strdel(&line);
	return (1);
}

static int		ft_fill_map(t_filler *f)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	line = NULL;
	while (i < f->l)
	{
		if (get_next_line(0, &line) < 1)
			return (-1);
		if (ft_strlen(line) != (size_t)f->c + 4)
		{
			ft_strdel(&line);
			return (-1);
		}
		j = 0;
		while (j < f->c)
		{
			if (line[4 + j] == 'X')
				f->maps[i][j] = 2;
			else if (line[4 + j] == 'O')
				f->maps[i][j] = 1;
			else if (line[4 + j] == '.')
				f->maps[i][j] = 0;
			else
				f->maps[i][j] = 3;
			j++;
		}
		ft_strdel(&line);
		i++;
	}
	return (1);
}

int				ft_get_map(t_filler *f, char *line)
{
	if (f->l == 0)
	{
		if (ft_allocate_map(f, line) == -1)
			return (-1);
	}
	else
		ft_strdel(&line);
	if (get_next_line(0, &line) < 1)
		return (-1);
	ft_strdel(&line);
	if (ft_fill_map(f) == -1)
		return (-1);
	return (1);
}
