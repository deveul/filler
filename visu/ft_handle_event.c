/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:51:59 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/08 13:00:01 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static int	ft_play_one_move(t_env *env, int *ret, int wait)
{
	int		i;

	i = 0;
	while (i < wait)
		i++;
	SDL_SetRenderTarget(env->ren, env->txt);
	*(ret) = ft_next_move(env);
	if (*(ret) == -1)
		return (-1);
	else if (*(ret) == 0)
		return (0);
	SDL_SetRenderTarget(env->ren, NULL);
	SDL_RenderCopy(env->ren, env->txt, NULL, NULL);
	SDL_SetRenderTarget(env->ren, env->pc);
	ft_draw_piece(env);
	SDL_SetRenderTarget(env->ren, NULL);
	SDL_RenderCopy(env->ren, env->titlep1, NULL, &env->rectnamep1);
	SDL_RenderCopy(env->ren, env->titlep2, NULL, &env->rectnamep2);
	SDL_RenderCopy(env->ren, env->titlepiece, NULL, &env->rectpiece);
	SDL_RenderCopy(env->ren, env->titlescore, NULL, &env->rectscore);
	ft_actualize_score(env);
	SDL_RenderPresent(env->ren);
	return (1);
}

static int	ft_automatic_play(t_env *env, int ret)
{
	if (env->event.key.keysym.scancode == SDL_SCANCODE_3)
	{
		while (ret > 0)
			ft_play_one_move(env, &ret, 0);
		return (ret);
	}
	else if (env->event.key.keysym.scancode == SDL_SCANCODE_2)
	{
		while (ret > 0)
			ft_play_one_move(env, &ret, 3000000);
		return (ret);
	}
	else if (env->event.key.keysym.scancode == SDL_SCANCODE_1)
	{
		while (ret > 0)
			ft_play_one_move(env, &ret, 10000000);
		return (ret);
	}
	return (ret);
}

int			ft_handle_event(t_env *env)
{
	int		ret;

	ret = 1;
	if (env->event.type == SDL_QUIT)
		return (-2);
	if (env->event.type == SDL_KEYDOWN)
	{
		if (env->event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			return (ft_play_one_move(env, &ret, 0));
		else
			return (ft_automatic_play(env, ret));
	}
	return (1);
}
