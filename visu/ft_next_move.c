/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:57:30 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/07 17:14:07 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	ft_choose_color(t_env *env)
{
	if (env->cptp2 < env->cptp1)
		env->p.col = 2;
	else
		env->p.col = 1;
}

static void	ft_player1_piece(t_env *env, int i, int j, int *is_running)
{
	if (env->map[i][j] != 1)
	{
		send_rect_to_fill(env, i, j, 1);
		env->map[i][j] = 1;
		if (*(is_running) == 1)
		{
			env->cptp2++;
			*(is_running) = 2;
		}
	}
}

static void	ft_player2_piece(t_env *env, int i, int j, int *is_running)
{
	if (env->map[i][j] != 2)
	{
		send_rect_to_fill(env, i, j, 2);
		env->map[i][j] = 2;
		if (*(is_running) == 1)
		{
			env->cptp1++;
			*(is_running) = 2;
		}
	}
}

static int	ft_put_next_piece(t_env *env, char *line, int *is_running)
{
	int		i;
	int		j;
	int		ret;

	if ((ret = get_next_line(0, &line)) < 1)
		return (ret);
	i = -1;
	while (++i < env->height_map)
	{
		ft_strdel(&line);
		if ((ret = get_next_line(0, &line)) < 1)
			return (ret);
		j = -1;
		while (++j < env->width_map)
		{
			if (line[j + 4] == '.')
				env->map[i][j] = 0;
			else if (line[j + 4] == 'O' || line[j + 4] == 'o')
				ft_player1_piece(env, i, j, is_running);
			else if (line[j + 4] == 'X' || line[j + 4] == 'x')
				ft_player2_piece(env, i, j, is_running);
		}
		ft_strdel(&line);
	}
	return (1);
}

int			ft_next_move(t_env *env)
{
	int		is_running;
	int		ret;
	char	*line;

	is_running = 1;
	while (is_running)
	{
		ft_choose_color(env);
		if ((ret = get_next_line(0, &line)) < 1)
			return (ret);
		if (!ft_strstr(line, "Plateau"))
			ft_strdel(&line);
		else
		{
			ft_strdel(&line);
			if (ft_put_next_piece(env, line, &is_running) == -1)
				return (-1);
			if (ft_get_current_piece(&env->p, line, env->p.col) == -1)
				return (-1);
			is_running = 0;
		}
	}
	return (1);
}
