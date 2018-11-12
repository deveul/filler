/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:39:54 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/12 11:30:33 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

static void		ft_init_filler(t_filler *f)
{
	f->fd = open("error", O_RDWR);
	f->mine = 0;
	f->l = 0;
	f->c = 0;
	f->oppocpt = 0;
	f->prev_cpt = -1;
}

static void		ft_free_piece(t_piece *p)
{
	int		i;

	i = 0;
	while (i < p->y)
		free(p->spiece[i++]);
	free(p->spiece);
}

static void		ft_first_read(t_filler *f, char *line)
{
	if (ft_strstr(line, "p2"))
	{
		f->mine = 2;
		f->other = 1;
	}
	else if (ft_strstr(line, "p1"))
	{
		f->mine = 1;
		f->other = 2;
	}
	ft_strdel(&line);
}

int				ft_play(t_filler *f, char *line)
{
	t_piece		p;
	t_point		point;
	int			pos;

	if (ft_get_map(f, line) == -1)
		return (-1);
	if ((ft_get_piece(f, &p, line) == -1))
		return (-1);
	if ((pos = ft_put_piece(f, &p)) == -1)
	{
		ft_printf("0 0");
		ft_free_piece(&p);
		return (0);
	}
	else
	{
		point.x = pos % f->c - p.xmin;
		point.y = pos / f->c - p.ymin;
		ft_printf("%d %d\n", point.y, point.x);
		ft_free_piece(&p);
	}
	return (1);
}

int				main(void)
{
	t_filler	f;
	char		*line;
	int			i;

	ft_init_filler(&f);
	i = 0;
	while (1)
	{
		if (get_next_line(0, &line) > 0)
		{
			if (f.mine == 0)
				ft_first_read(&f, line);
			else
			{
				if (ft_play(&f, line) == 0)
				{
					while (i < f.l)
						free(f.maps[i++]);
					free(f.maps);
					return (0);
				}
			}
		}
	}
	return (0);
}
