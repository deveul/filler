/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_oppocpt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:06:08 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/09 16:53:45 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_get_oppocpt(t_filler *f)
{
	int		i;
	int		j;

	f->prev_cpt = f->oppocpt;
	f->oppocpt = 0;
	i = 0;
	while (i < f->l)
	{
		j = 0;
		while (j < f->c)
		{
			if (f->maps[i][j] == f->other)
				f->oppocpt++;
			j++;
		}
		i++;
	}
}
