/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:57:29 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/07 17:53:45 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_check_trigger(t_piece *p)
{
	if (p->trigger == -1)
	{
		p->trigger = 1;
		return (1);
	}
	else
		return (-1);
}

static int		ft_check_pos(t_filler *f, t_piece *p, int y, int x)
{
	int		i;
	int		j;

	i = -1;
	while (++i < p->y)
	{
		j = -1;
		while (++j < p->x)
		{
			if (p->spiece[i][j] == f->mine)
			{
				if (f->maps[y + i][x + j] == f->mine)
				{
					if (ft_check_trigger(p) == -1)
						return (-1);
				}
				else if (f->maps[y + i][x + j] == f->other)
					return (-1);
				else if (f->maps[y + i][x + j] == 3)
					return (-1);
			}
		}
	}
	return (p->trigger);
}

static void		ft_get_opponent(t_filler *f, t_point *pts)
{
	int			i;
	int			j;
	int			a;

	a = 0;
	i = 0;
	while (i < f->l && a < f->oppocpt)
	{
		j = 0;
		while (j < f->c && a < f->oppocpt)
		{
			if (f->maps[i][j] == f->other)
			{
				pts[a].x = j;
				pts[a].y = i;
				a++;
			}
			j++;
		}
		i++;
	}
}

static void		ft_update_values(t_filler *f, t_piece *p
		, t_sort *sort, t_point *pts)
{
	p->trigger = -1;
	if ((ft_check_pos(f, p, sort->y, sort->x)) == 1)
	{
		sort->value = ft_estimate_value(f, p, *sort, pts);
		if (sort->trigger++ == 0)
		{
			sort->current = sort->x + (f->c * sort->y);
			sort->best = sort->value;
		}
		else if (sort->value > sort->best)
		{
			sort->best = sort->value;
			sort->current = sort->x + (f->c * sort->y);
		}
	}
}

int				ft_put_piece(t_filler *f, t_piece *p)
{
	t_sort		sort;
	t_point		*pts;

	pts = NULL;
	sort.trigger = 0;
	sort.current = -1;
	sort.y = 0;
	if (!(pts = ft_memalloc(sizeof(t_point) * f->oppocpt)))
		return (-1);
	ft_get_opponent(f, pts);
	while ((sort.y + p->y) <= f->l)
	{
		sort.x = 0;
		while ((sort.x + p->x) <= f->c)
		{
			ft_update_values(f, p, &sort, pts);
			sort.x++;
		}
		sort.y++;
	}
	free(pts);
	return (sort.current);
}
