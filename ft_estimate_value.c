/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_estimate_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:53:05 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/08 13:17:06 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_check_linear(t_filler *f, t_sort pt, int i, int j)
{
	int		cpt;

	cpt = 0;
	if (pt.y + i + 1 < f->l)
		if (f->maps[pt.y + i + 1][pt.x + j] == f->other)
			cpt++;
	if (pt.y + i - 1 >= 0)
		if (f->maps[pt.y + i - 1][pt.x + j] == f->other)
			cpt++;
	if (pt.x + j + 1 < f->c)
		if (f->maps[pt.y + i][pt.x + j + 1] == f->other)
			cpt++;
	if (pt.x + j - 1 >= 0)
		if (f->maps[pt.y + i][pt.x + j - 1] == f->other)
			cpt++;
	return (cpt);
}

static int		ft_contact_point(t_filler *f, t_piece *p, t_sort pt)
{
	int		i;
	int		j;
	int		cpt;

	cpt = 0;
	i = 0;
	while (i < p->y)
	{
		j = 0;
		while (j < p->x)
		{
			if (p->spiece[i][j] == f->mine)
				cpt += ft_check_linear(f, pt, i, j);
			j++;
		}
		i++;
	}
	return (cpt);
}

int				ft_estimate_value(t_filler *f, t_piece *p, \
		t_sort pt, t_point *pts)
{
	int		cp;
	int		distance;

	distance = 0;
	if ((cp = ft_contact_point(f, p, pt)) != 0)
		return (cp);
	if (f->prev_cpt == f->oppocpt)
		return (-1);
//	return (-1);
	distance = ft_distance(f, p, pts, pt);
	return (distance);
}
