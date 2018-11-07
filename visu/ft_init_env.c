/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:27:31 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/07 11:09:09 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	ft_init_var(t_env *env, int *i)
{
	*(i) = 1;
	env->p1 = NULL;
	env->p2 = NULL;
	env->width_map = -1;
	env->height_map = -1;
}

static int	ft_get_player1(t_env *env, char *line)
{
	int		len;
	char	*count;

	if (!(count = ft_strstr(line, "players/")))
	{
		ft_printf("put filler player in directory players\n");
		return (-1);
	}
	else
	{
		len = ft_strlen(count + 8) - 1;
		env->p1 = ft_strndup(count + 8, len);
	}
	return (1);
}

static int	ft_get_player2(t_env *env, char *line)
{
	int		len;
	char	*count;

	if (!(count = ft_strstr(line, "players/")))
	{
		ft_printf("put filler player in directory players\n");
		return (-1);
	}
	else
	{
		len = ft_strlen(count + 8) - 1;
		env->p2 = ft_strndup(count + 8, len);
	}
	return (1);
}

static void	ft_get_tray(t_env *env, char *line)
{
	int		cpt;

	cpt = 0;
	while (!ft_isdigit(line[cpt]))
		cpt++;
	env->height_map = ft_atoi(line + cpt);
	while (ft_isdigit(line[cpt]))
		cpt++;
	cpt++;
	env->width_map = ft_atoi(line + cpt);
}

int			ft_init_env(t_env *env, int *is_running)
{
	int		i;
	char	*line;

	ft_init_var(env, &i);
	line = NULL;
	while (i)
	{
		get_next_line(0, &line);
		if (ft_strstr(line, "exec p1"))
			if (ft_get_player1(env, line) == -1)
				return (-1);
		if (ft_strstr(line, "exec p2"))
			if (ft_get_player2(env, line) == -1)
				return (-1);
		if (ft_strstr(line, "Plateau"))
			ft_get_tray(env, line);
		if (env->height_map != -1)
			i = 0;
	}
	*(is_running) = 2;
	return (1);
}
