/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:39:54 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/17 11:28:23 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_init_filler(t_filler *f)
{
	f->mine = 0;
	f->l = 0;
	f->c = 0;
	f->oppocpt = 0;
	f->prev_cpt = -1;
}

static int		ft_first_read(t_filler *f, char *line)
{
	if (ft_strstr(line, "exec p1 :") && ft_strstr(line, "vrenaudi.filler"))
	{
		f->mine = 1;
		f->other = 2;
	}
	else if (ft_strstr(line, "exec p2 :") && ft_strstr(line, "vrenaudi.filler"))
	{
		f->mine = 2;
		f->other = 1;
	}
	else
	{
		ft_strdel(&line);
		return (-1);
	}
	ft_strdel(&line);
	return (0);
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
		ft_free_spiece(&p);
		return (0);
	}
	else
	{
		point.x = pos % f->c - p.xmin;
		point.y = pos / f->c - p.ymin;
		ft_printf("%d %d\n", point.y, point.x);
		ft_free_spiece(&p);
	}
	return (1);
}

static int		ft_analyze_ret(t_filler *f, int ret)
{
	int			i;

	i = 0;
	if (ret == 0)
	{
		while (i < f->l)
			free(f->maps[i++]);
		free(f->maps);
		return (0);
	}
	else if (ret == -1)
	{
		if (f->l != 0 && f->l < 1000)
		{
			while (i < f->l)
				free(f->maps[i++]);
			free(f->maps);
		}
		return (-1);
	}
	return (1);
}

int				main(void)
{
	t_filler	f;
	char		*line;
	int			ret;
	int			tmp;

	ft_init_filler(&f);
	while (1)
	{
		if (get_next_line(0, &line) > 0)
		{
			if (f.mine == 0)
			{
				if (ft_first_read(&f, line) == -1)
					return (-1);
			}
			else
			{
				tmp = ft_play(&f, line);
				if ((ret = ft_analyze_ret(&f, tmp)) < 1)
					return (ret);
			}
		}
	}
	return (0);
}
