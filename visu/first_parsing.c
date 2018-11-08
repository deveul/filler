/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 09:57:18 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/08 15:22:26 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static int	ft_fill_map(t_env *env, char *line, int i, int j)
{
	while (i < env->height_map)
	{
		if (get_next_line(0, &line) < 1)
			return (-1);
		if (!(env->map[i] = ft_memalloc(sizeof(int) * env->width_map)))
			return (-1);
		j = 0;
		while (j < env->width_map)
		{
			if (line[j + 4] == '.')
				env->map[i][j] = 0;
			else if (line[j + 4] == 'O')
				env->map[i][j] = 1;
			else if (line[j + 4] == 'X')
				env->map[i][j] = 2;
			else
				env->map[i][j] = 3;
			j++;
		}
		i++;
		ft_strdel(&line);
	}
	return (1);
}

int			ft_first_parsing(t_env *env, int *is_running)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	env->cptp1 = 1;
	env->cptp2 = 0;
	if (get_next_line(0, &line) < 1)
		return (-1);
	ft_strdel(&line);
	if (!(env->map = ft_memalloc(sizeof(int*) * env->height_map)))
		return (-1);
	if (ft_fill_map(env, line, i, j) == -1)
		return (-1);
	if (ft_get_current_piece(&env->p, line, 1) == -1)
		return (-1);
	*(is_running) = 3;
	return (0);
}
