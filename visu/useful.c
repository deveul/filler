/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:16:18 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/07 15:53:43 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void			ft_pick_color(t_env *env, int r, int g, int b)
{
	env->color.r = r;
	env->color.g = g;
	env->color.b = b;
	env->color.a = 255;
}

void			send_rect_to_fill(t_env *env, int i, int j, int color)
{
	SDL_Rect	rectangle;

	rectangle.w = WIDTH / (env->width_map);
	rectangle.h = HEIGHT / (env->height_map);
	rectangle.x = (WIDTH / 8) + j * (WIDTH / (env->width_map));
	rectangle.y = (HEIGHT / 4) + i * (HEIGHT / (env->height_map));
	if (color == 1)
	{
		SDL_SetRenderDrawColor(env->ren, 53, 75, 96, 255);
		SDL_RenderFillRect(env->ren, &rectangle);
	}
	if (color == 2)
	{
		SDL_SetRenderDrawColor(env->ren, 233, 139, 57, 255);
		SDL_RenderFillRect(env->ren, &rectangle);
	}
	SDL_SetRenderDrawColor(env->ren, 163, 177, 178, 255);
	SDL_RenderDrawRect(env->ren, &rectangle);
}
