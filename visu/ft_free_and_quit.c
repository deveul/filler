/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_quit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:03:42 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/08 16:01:24 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void			ft_free_piece(t_env *env)
{
	int		i;

	i = 0;
	if (env->p.y == -1)
		return ;
	while (i < env->p.y)
		free(env->p.spiece[i++]);
	free(env->p.spiece);
}

static void		ft_free_map(t_env *env)
{
	int		i;

	i = 0;
	if (env->height_map == -1 || env->width_map == -1)
		return ;
	while (i < env->height_map)
	{
		free(env->map[i]);
		i++;
	}
	free(env->map);
}

int				ft_quit_all_neg(t_env *env)
{
	ft_strdel(&env->p1);
	ft_strdel(&env->p2);
	ft_strdel(&env->namep1);
	ft_strdel(&env->namep2);
	ft_strdel(&env->score);
	ft_strdel(&env->winner);
	ft_free_map(env);
	TTF_CloseFont(env->font);
	SDL_DestroyRenderer(env->ren);
	SDL_DestroyWindow(env->win);
	SDL_Quit();
	return (-1);
}

int				ft_quit_all(t_env *env)
{
	ft_strdel(&env->p1);
	ft_strdel(&env->p2);
	ft_strdel(&env->namep1);
	ft_strdel(&env->namep2);
	ft_strdel(&env->score);
	ft_strdel(&env->winner);
	ft_free_map(env);
	TTF_CloseFont(env->font);
	SDL_DestroyRenderer(env->ren);
	SDL_DestroyWindow(env->win);
	SDL_Quit();
	return (0);
}
