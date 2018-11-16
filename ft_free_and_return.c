/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_return.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:30:22 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/16 14:33:36 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_free_piece(t_piece *p)
{
	int		i;

	i = 0;
	while (i < (p->height + 1))
	{
		ft_strdel(&p->piece[i]);
		i++;
	}
	free(p->piece);
}

int		ft_free_and_return(char *line)
{
	ft_strdel(&line);
	return (-1);
}
