/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:13:46 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/17 11:28:21 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_allocate_map(t_filler *f)
{
	int		i;

	i = 0;
	if (!(f->maps = ft_memalloc(sizeof(int*) * f->l)))
		return (-1);
	while (i < f->l)
	{
		if (!(f->maps[i] = ft_memalloc(sizeof(int) * f->c)))
			return (-1);
		i++;
	}
	return (1);
}

static int		ft_get_map_size(t_filler *f, char *line)
{
	int		cpt;

	cpt = 8;
	if (!ft_strstr(line, "Plateau"))
		return (ft_free_and_return(line));
	if (!line[cpt])
		return (ft_free_and_return(line));
	f->l = ft_atoi(line + cpt);
	while (line[cpt] && ft_isdigit(line[cpt]))
		cpt++;
	if (!line[cpt])
		return (ft_free_and_return(line));
	while (line[cpt] && !ft_isdigit(line[cpt]))
		cpt++;
	if (!line[cpt])
		return (ft_free_and_return(line));
	f->c = ft_atoi(line + (cpt));
	ft_strdel(&line);
	if (f->c == 0 || f->l == 0 || f->l > 999)
		return (-1);
	if (ft_allocate_map(f) == -1)
		return (-1);
	return (1);
}

static void		ft_fill_map2(t_filler *f, char *line, int i, int j)
{
	if (line[4 + j] == 'X')
		f->maps[i][j] = 2;
	else if (line[4 + j] == 'O')
		f->maps[i][j] = 1;
	else if (line[4 + j] == '.')
		f->maps[i][j] = 0;
	else
		f->maps[i][j] = 3;
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
			return (ft_free_and_return(line));
		j = 0;
		while (j < f->c)
		{
			ft_fill_map2(f, line, i, j);
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
		if (ft_get_map_size(f, line) == -1)
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
