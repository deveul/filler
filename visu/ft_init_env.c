/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:27:31 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/12 10:42:56 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	ft_init_var(t_env *env, int *i)
{
	*(i) = 1;
	env->width_map = -1;
	env->height_map = -1;
}

static int	ft_get_player(t_env *env, char *line, int nb)
{
	int		len;
	char	*count;

	if (!(count = ft_strstr(line, "players/")))
	{
		ft_printf("put filler player in directory players\n");
		return (-1);
	}
	else if (nb == 1)
	{
		len = ft_strlen(count + 8) - 1;
		env->p1 = ft_strndup(count + 8, len);
	}
	else if (nb == 2)
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

static int	ft_is_there_players(t_env *env, char *line)
{
	int		ret;

	if (ft_strstr(line, "exec p1"))
		if ((ret = ft_get_player(env, line, 1)) == -1)
			return (-1);
	if (ft_strstr(line, "exec p2"))
		if ((ret = ft_get_player(env, line, 2)) == -1)
			return (-1);
	return (1);
}

int			ft_init_env(t_env *env, int *is_running)
{
	int		i;
	int		ret;
	char	*line;

	ft_init_var(env, &i);
	line = NULL;
	while (i)
	{
		get_next_line(0, &line);
		if (ft_strstr(line, "error") && !ft_strstr(line, "exec"))
		{
			ft_printf("error detected by the VM.\n");
			return (-1);
		}
		if ((ret = ft_is_there_players(env, line)) == -1)
			return (-1);
		if (ft_strstr(line, "Plateau"))
			ft_get_tray(env, line);
		ft_strdel(&line);
		if (env->height_map != -1)
			i = 0;
	}
	*(is_running) = 2;
	return (1);
}
