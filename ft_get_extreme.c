/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_extreme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:03:23 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/16 15:10:45 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_replace_value(t_piece *p, int i, int j)
{
	if (p->piece[i][j] != '.' && p->piece[i][j] != '*')
	{
		ft_free_piece(p);
		return (-1);
	}
	if (p->xmin == -1)
	{
		p->xmin = j;
		p->ymin = i;
		p->xmax = j;
		p->ymax = i;
	}
	if (p->piece[i][j] == '*')
	{
		if (p->xmin > j)
			p->xmin = j;
		if (p->xmax < j)
			p->xmax = j;
		if (p->ymin > i)
			p->ymin = i;
		if (p->ymax < i)
			p->ymax = i;
	}
	return (1);
}

int			ft_get_extreme(t_piece *p, char *line)
{
	int		i;
	int		j;

	p->xmin = -1;
	i = -1;
	while (++i < p->height)
	{
		if (get_next_line(0, &line) < 1)
			return (-1);
		if (ft_strlen(line) != (size_t)p->width)
		{
			ft_free_piece(p);
			return (ft_free_and_return(line));
		}
		p->piece[i] = line;
		line = NULL;
		j = -1;
		while (++j < p->width)
			ft_replace_value(p, i, j);
	}
	p->x = p->xmax - p->xmin + 1;
	p->y = p->ymax - p->ymin + 1;
	return (1);
}
