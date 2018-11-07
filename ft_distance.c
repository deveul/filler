/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:35:55 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/07 19:42:49 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

static int	ft_calculate_tmp(t_point *pts, int cpt, t_point ij, t_sort pt)
{
	int		tmp1;
	int		tmp2;
	int		x;
	int		y;

	x = pt.x;
	y = pt.y;
	if ((tmp1 = y + ij.x - pts[cpt].y) < 0)
		tmp1 = 0 - tmp1;
	if ((tmp2 = x + ij.y - pts[cpt].x) < 0)
		tmp2 = 0 - tmp2;
	return (tmp1 + tmp2);
}

static int	ft_measure(t_point *pts, t_sort pt, t_point ij, int oppocpt)
{
	int		cpt;
	int		ret;
	int		tmp;

	cpt = 0;
	while (cpt < oppocpt)
	{
		tmp = ft_calculate_tmp(pts, cpt, ij, pt);
		if (ret == -1)
			ret = tmp;
		else if (tmp < ret)
			ret = tmp;
		cpt++;
	}
	return (ret);
}

int			ft_distance(t_filler *f, t_piece *p, t_point *pts, t_sort pt)
{
	t_point	ij;
	int		ret;
	int		oppocpt;

	ij.x = 0;
	ret = -1;
	oppocpt = f->oppocpt;
	while (ij.x < p->y)
	{
		ij.y = 0;
		while (ij.y < p->x)
		{
			if (p->spiece[ij.x][ij.y] == f->mine)
				ret = ft_measure(pts, pt, ij, oppocpt);
			ij.y++;
		}
		ij.x++;
	}
	return (-ret);
}
