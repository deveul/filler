/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_original_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:29:57 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/12 10:09:38 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	ft_draw_map_rectangle(t_env *env, int i, int j)
{
	SDL_Rect	rectangle;

	rectangle.w = WIDTH / (env->width_map);
	rectangle.h = HEIGHT / (env->height_map);
	rectangle.x = (WIDTH / 8) + j * (WIDTH / (env->width_map));
	rectangle.y = (HEIGHT / 4) + i * (HEIGHT / (env->height_map));
	if (env->map[i][j] == 1)
	{
		SDL_SetRenderDrawColor(env->ren, 53, 75, 96, 255);
		SDL_RenderFillRect(env->ren, &rectangle);
	}
	if (env->map[i][j] == 2)
	{
		SDL_SetRenderDrawColor(env->ren, 233, 139, 57, 255);
		SDL_RenderFillRect(env->ren, &rectangle);
	}
	if (env->map[i][j] == 3)
	{
		SDL_SetRenderDrawColor(env->ren, 233, 139, 57, 255);
		SDL_RenderFillRect(env->ren, &rectangle);
	}
	SDL_SetRenderDrawColor(env->ren, 163, 177, 178, 255);
	SDL_RenderDrawRect(env->ren, &rectangle);
}

static void	ft_draw_map(t_env *env)
{
	int			i;
	int			j;

	i = 0;
	while (i < env->height_map)
	{
		j = 0;
		while (j < env->width_map)
		{
			ft_draw_map_rectangle(env, i, j);
			j++;
		}
		i++;
	}
}

static void	ft_original_draw3(t_env *env)
{
	env->rectscore.x = WIDTH * 1.2;
	env->rectscore.y = HEIGHT * 0.8;
	SDL_RenderCopy(env->ren, env->titlescore, NULL, &env->rectscore);
	ft_pick_color(env, 53, 75, 96);
	env->surf = TTF_RenderText_Blended(env->font, "P1 : 0", env->color);
	env->originalscore = SDL_CreateTextureFromSurface(env->ren, env->surf);
	env->rectoriscore.w = env->surf->w;
	env->rectoriscore.h = env->surf->h;
	env->rectoriscore.x = WIDTH * 1.2;
	env->rectoriscore.y = HEIGHT * 0.85;
	SDL_FreeSurface(env->surf);
	SDL_RenderCopy(env->ren, env->originalscore, NULL, &env->rectoriscore);
	ft_pick_color(env, 233, 139, 57);
	env->surf = TTF_RenderText_Blended(env->font, "P2 : 0", env->color);
	env->originalscore = SDL_CreateTextureFromSurface(env->ren, env->surf);
	env->rectoriscore.w = env->surf->w;
	env->rectoriscore.h = env->surf->h;
	env->rectoriscore.x = WIDTH * 1.2;
	env->rectoriscore.y = HEIGHT * 0.9;
	SDL_FreeSurface(env->surf);
	SDL_RenderCopy(env->ren, env->originalscore, NULL, &env->rectoriscore);
	SDL_RenderPresent(env->ren);
}

static void	ft_original_draw2(t_env *env)
{
	env->surf = TTF_RenderText_Blended(env->font, env->namep2, env->color);
	env->titlep2 = SDL_CreateTextureFromSurface(env->ren, env->surf);
	env->rectnamep2.w = env->surf->w;
	env->rectnamep2.h = env->surf->h;
	env->rectnamep2.x = WIDTH / 15;
	env->rectnamep2.y = HEIGHT / 8;
	SDL_FreeSurface(env->surf);
	SDL_RenderCopy(env->ren, env->titlep2, NULL, &env->rectnamep2);
	ft_pick_color(env, 255, 255, 255);
	env->surf = TTF_RenderText_Blended(env->font, "Piece :", env->color);
	env->titlepiece = SDL_CreateTextureFromSurface(env->ren, env->surf);
	env->rectpiece.w = env->surf->w;
	env->rectpiece.h = env->surf->h;
	env->rectpiece.x = WIDTH * 1.2;
	env->rectpiece.y = HEIGHT * 0.3;
	SDL_FreeSurface(env->surf);
	SDL_RenderCopy(env->ren, env->titlepiece, NULL, &env->rectpiece);
	env->surf = TTF_RenderText_Blended(env->font, "Score :", env->color);
	env->titlescore = SDL_CreateTextureFromSurface(env->ren, env->surf);
	env->rectscore.w = env->surf->w;
	env->rectscore.h = env->surf->h;
	SDL_FreeSurface(env->surf);
	ft_original_draw3(env);
}

void		ft_original_draw(t_env *env)
{
	SDL_SetRenderTarget(env->ren, env->txt);
	ft_draw_map(env);
	SDL_SetRenderTarget(env->ren, env->pc);
	SDL_RenderCopy(env->ren, env->txt, NULL, NULL);
	ft_draw_piece(env);
	SDL_SetRenderTarget(env->ren, NULL);
	SDL_RenderCopy(env->ren, env->pc, NULL, NULL);
	env->namep1 = ft_strjoin("P1 : ", ft_strtoupper(env->p1));
	ft_strdel(&env->p1);
	ft_pick_color(env, 53, 75, 96);
	env->surf = TTF_RenderText_Blended(env->font, env->namep1, env->color);
	env->titlep1 = SDL_CreateTextureFromSurface(env->ren, env->surf);
	env->rectnamep1.w = env->surf->w;
	env->rectnamep1.h = env->surf->h;
	env->rectnamep1.x = WIDTH / 15;
	env->rectnamep1.y = HEIGHT / 15;
	SDL_FreeSurface(env->surf);
	SDL_RenderCopy(env->ren, env->titlep1, NULL, &env->rectnamep1);
	env->namep2 = ft_strjoin("P2 : ", ft_strtoupper(env->p2));
	ft_strdel(&env->p2);
	ft_pick_color(env, 233, 139, 57);
	ft_original_draw2(env);
}
