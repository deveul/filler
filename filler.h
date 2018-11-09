/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:23:24 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/09 16:50:59 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./libft/printf/ft_printf.h"
# include "./libft/libft/get_next_line.h"
# include <fcntl.h>

typedef struct	s_filler
{
	int			mine;
	int			other;
	int			l;
	int			c;
	int			**maps;
	int			fd;
	int			oppocpt;
	int			prev_cpt;
}				t_filler;

typedef struct	s_piece
{
	int			height;
	int			width;
	char		**piece;
	int			**spiece;
	int			x;
	int			y;
	int			xmin;
	int			xmax;
	int			ymin;
	int			ymax;
	int			trigger;
}				t_piece;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_sort
{
	int			x;
	int			y;
	int			current;
	int			best;
	int			value;
	int			trigger;
}				t_sort;

void			ft_get_oppocpt(t_filler *f);
void			ft_print_infos(t_filler *f, t_piece *p);
int				ft_get_map(t_filler *f, char *line);
int				ft_get_piece(t_filler *f, t_piece *p, char *line);
int				ft_put_piece(t_filler *f, t_piece *p);
int				ft_estimate_value(t_filler *f, t_piece *p, \
		t_sort pt, t_point *pts);

#endif
