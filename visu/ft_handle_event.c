/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:51:59 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/07 20:28:23 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	ft_actualize_score(t_env *env)
{
	ft_pick_color(env, 53, 75, 96);
	env->score = ft_strjoin("P1 : ", ft_itoa(env->cptp2));
	env->surf = TTF_RenderText_Blended(env->font, env->score, env->color);
	env->originalscore = SDL_CreateTextureFromSurface(env->ren, env->surf);
	env->rectoriscore.w = env->surf->w;
	env->rectoriscore.h = env->surf->h;
	env->rectoriscore.x = WIDTH * 1.2;
	env->rectoriscore.y = HEIGHT * 0.85;
	SDL_FreeSurface(env->surf);
	SDL_RenderCopy(env->ren, env->originalscore, NULL, &env->rectoriscore);
	ft_pick_color(env, 233, 139, 57);
	env->score = ft_strjoin("P2 : ", ft_itoa(env->cptp1));
	env->surf = TTF_RenderText_Blended(env->font, env->score, env->color);
	env->originalscore = SDL_CreateTextureFromSurface(env->ren, env->surf);
	env->rectoriscore.w = env->surf->w;
	env->rectoriscore.h = env->surf->h;
	env->rectoriscore.x = WIDTH * 1.2;
	env->rectoriscore.y = HEIGHT * 0.9;
	SDL_FreeSurface(env->surf);
	SDL_RenderCopy(env->ren, env->originalscore, NULL, &env->rectoriscore);
}

static void	ft_play_one_move(t_env *env, int *ret)
{
	SDL_SetRenderTarget(env->ren, env->txt);
	*(ret) = ft_next_move(env);
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
}

int			ft_handle_event(t_env *env)
{
	int		ret;
	int		i;

	ret = 1;
	if (env->event.type == SDL_QUIT)
		return (-2);
	if (env->event.type == SDL_KEYDOWN)
	{
		if (env->event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			SDL_SetRenderTarget(env->ren, env->txt);
			ret = ft_next_move(env);
			if (ret == -1)
				return (-1);
			else if (ret == 0)
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
		}
		if (env->event.key.keysym.scancode == SDL_SCANCODE_3)
		{
			while (ret > 0)
				ft_play_one_move(env, &ret);
			return (ret);
		}
		if (env->event.key.keysym.scancode == SDL_SCANCODE_2)
		{
			while (ret > 0)
			{
				i = 0;
				while (i < 3000000)
					i++;
				ft_play_one_move(env, &ret);
			}
			return (ret);
		}
		if (env->event.key.keysym.scancode == SDL_SCANCODE_1)
		{
			while (ret > 0)
			{
				i = 0;
				while (i < 10000000)
					i++;
				ft_play_one_move(env, &ret);
			}
			return (ret);
		}
	}
	return (1);
}
