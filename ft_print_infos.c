/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:50:41 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/31 17:46:49 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_print_infos2(t_filler *f, t_piece *p)
{
	int		i;
	int		j;

	i = 0;
	ft_dprintf(f->fd, "piece:\n");
	while (i < p->y)
	{
		j = 0;
		while (j < p->x)
		{
			ft_dprintf(f->fd, "%d|", p->spiece[i][j]);
			j++;
		}
		i++;
		ft_dprintf(f->fd, "\n");
	}
	ft_dprintf(f->fd, "maps : ligne = %d, colonne = %d\n", f->l, f->c);
	ft_dprintf(f->fd, "piece originale: ligne = %d, colonne = %d\n", \
			p->height, p->width);
	ft_dprintf(f->fd, "piece reduite: ligne = %d, colonne = %d\n", p->y, p->x);
	ft_dprintf(f->fd, "mine:%d\n", f->mine);
}

void		ft_print_infos(t_filler *f, t_piece *p)
{
	int		i;
	int		j;

	i = 0;
	ft_dprintf(f->fd, "maps:\n");
	while (i < f->l)
	{
		j = 0;
		ft_dprintf(f->fd, "line n %d	", i);
		while (j < f->c)
		{
			ft_dprintf(f->fd, "%d|", f->maps[i][j]);
			j++;
		}
		ft_dprintf(f->fd, "\n");
		i++;
	}
	ft_print_infos2(f, p);
}
