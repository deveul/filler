/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:22:02 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/08 11:28:50 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		ft_print_winner2(t_env *env)
{
	env->surf = TTF_RenderText_Blended(env->font, env->winner, env->color);
	env->txtwinner = SDL_CreateTextureFromSurface(env->ren, env->surf);
	env->rectwinner.w = env->surf->w;
	env->rectwinner.h = env->surf->h;
	env->rectwinner.x = WIDTH * 0.2;
	env->rectwinner.y = HEIGHT * 1.3;
	SDL_FreeSurface(env->surf);
	SDL_RenderCopy(env->ren, env->txtwinner, NULL, &env->rectwinner);
	ft_actualize_score(env);
	SDL_RenderPresent(env->ren);
}

void			ft_print_winner(t_env *env)
{
	SDL_SetRenderTarget(env->ren, env->txt);
	SDL_SetRenderTarget(env->ren, NULL);
	SDL_RenderCopy(env->ren, env->txt, NULL, NULL);
	SDL_SetRenderTarget(env->ren, env->pc);
	SDL_SetRenderTarget(env->ren, NULL);
	SDL_RenderCopy(env->ren, env->titlep1, NULL, &env->rectnamep1);
	SDL_RenderCopy(env->ren, env->titlep2, NULL, &env->rectnamep2);
	SDL_RenderCopy(env->ren, env->titlescore, NULL, &env->rectscore);
	if (env->cptp1 > env->cptp2)
	{
		ft_pick_color(env, 233, 139, 57);
		env->winner = ft_strjoin("WINNER IS ", env->namep2);
	}
	else
	{
		ft_pick_color(env, 53, 75, 96);
		env->winner = ft_strjoin("WINNER IS ", env->namep1);
	}
	ft_print_winner2(env);
}
