/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:51:53 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/17 12:33:11 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_allocate_piece(t_piece *p)
{
	int		i;

	i = -1;
	if (!(p->piece = ft_memalloc(sizeof(char*) * (p->height + 1))))
		return (-1);
	while (++i < (p->height + 1))
		p->piece[i] = NULL;
	return (1);
}

static int	ft_get_piece_size(t_piece *p, char *line)
{
	int		cpt;

	cpt = 0;
	if (get_next_line(0, &line) < 1)
		return (-1);
	if (!ft_strstr(line, "Piece"))
		return (-1);
	while (line[cpt] && !(ft_isdigit(line[cpt])))
		cpt++;
	if (!line[cpt])
		return (ft_free_and_return(line));
	p->height = ft_atoi(line + cpt);
	while (line[cpt] && ft_isdigit(line[cpt]))
		cpt++;
	if (!line[cpt])
		return (ft_free_and_return(line));
	p->width = ft_atoi(line + (cpt + 1));
	ft_strdel(&line);
	if (p->height == 0 || p->width == 0)
		return (-1);
	return (ft_allocate_piece(p));
}

static int	ft_fill_piece(t_filler *f, t_piece *p)
{
	int		i;
	int		j;

	if (!(p->spiece = ft_memalloc(sizeof(int*) * p->y)))
		return (-1);
	i = 0;
	while (i < p->y)
	{
		j = 0;
		if (!(p->spiece[i] = ft_memalloc(sizeof(int) * p->x)))
			return (-1);
		while (j < p->x)
		{
			if (p->piece[i + p->ymin][j + p->xmin] == '.')
				p->spiece[i][j] = 0;
			else if (p->piece[i + p->ymin][j + p->xmin] == '*')
				p->spiece[i][j] = f->mine;
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_get_piece(t_filler *f, t_piece *p, char *line)
{
	int		i;

	i = 0;
	p->piece = NULL;
	p->spiece = NULL;
	if (ft_get_piece_size(p, line) == -1)
		return (-1);
	if (ft_get_extreme(p, line) == -1)
		return (-1);
	if (ft_fill_piece(f, p) == -1)
		return (-1);
	while (i < p->height)
		ft_strdel(&p->piece[i++]);
	free(p->piece);
	return (1);
}
