/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:54:06 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/08 15:28:09 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	ft_actual_draw(t_env *env, SDL_Rect rectangle)
{
	SDL_RenderDrawRect(env->ren, &rectangle);
	if (env->p.col == 1)
	{
		SDL_SetRenderDrawColor(env->ren, 53, 75, 96, 255);
		SDL_RenderFillRect(env->ren, &rectangle);
	}
	else if (env->p.col == 2)
	{
		SDL_SetRenderDrawColor(env->ren, 233, 139, 57, 255);
		SDL_RenderFillRect(env->ren, &rectangle);
	}
	SDL_SetRenderDrawColor(env->ren, 163, 177, 178, 255);
	SDL_RenderDrawRect(env->ren, &rectangle);
}

void		ft_draw_piece(t_env *env)
{
	SDL_Rect	rectangle;
	int			i;
	int			j;

	i = 0;
	while (i < env->p.y)
	{
		j = 0;
		while (j < env->p.x)
		{
			if (env->p.spiece[i][j] == env->p.col)
			{
				rectangle.w = WIDTH / (env->width_map);
				rectangle.h = HEIGHT / (env->height_map);
				rectangle.x = WIDTH * 1.2 + j * WIDTH / env->width_map;
				rectangle.y = HEIGHT * 0.4 + i * HEIGHT / env->height_map;
				ft_actual_draw(env, rectangle);
			}
			j++;
		}
		i++;
	}
}
