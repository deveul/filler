/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:41:50 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/07 19:14:10 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static int	ft_quit_all_neg(t_env *env)
{
	TTF_CloseFont(env->font);
	SDL_DestroyRenderer(env->ren);
	SDL_DestroyWindow(env->win);
	SDL_Quit();
	return (-1);
}

static int	ft_quit_all(t_env *env)
{
	TTF_CloseFont(env->font);
	SDL_DestroyRenderer(env->ren);
	SDL_DestroyWindow(env->win);
	SDL_Quit();
	return (1);
}

static int	ft_init_visu(t_env *env, int *fd, int *is_running)
{
	*(is_running) = 1;
	*(fd) = open("salut", O_CREAT | O_RDWR, 0777);
	env->p.col = 1;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_printf("unable to initialize SDL: %s", SDL_GetError());
		return (-1);
	}
	TTF_Init();
	env->font = TTF_OpenFont("CSMS.ttf", HEIGHT / 20);
	if (!(env->win = SDL_CreateWindow("visu filler", SDL_WINDOWPOS_UNDEFINED, \
					SDL_WINDOWPOS_UNDEFINED, WIDTH * 1.5, HEIGHT * 1.5, 0)))
		return (-1);
	if (!(env->ren = SDL_CreateRenderer(env->win, -1, SDL_RENDERER_ACCELERATED \
					| SDL_RENDERER_TARGETTEXTURE)))
		return (-1);
	if (!(env->txt = SDL_CreateTexture(env->ren, SDL_PIXELFORMAT_RGBA8888, \
					SDL_TEXTUREACCESS_TARGET, WIDTH * 1.5, HEIGHT * 1.5)))
		return (-1);
	ft_pick_color(env, 255, 255, 255);
	return (1);
}

static void	ft_print_winner(t_env *env)
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

int			main(void)
{
	t_env		env;
	int			is_running;
	int			fd;
	int			ret;

	if (ft_init_visu(&env, &fd, &is_running) == -1)
		return (-1);
	while (is_running)
	{
		if (is_running == 1)
			if (ft_init_env(&env, &is_running) == -1)
				return (ft_quit_all_neg(&env));
		if (is_running == 2)
		{
			if (ft_first_parsing(&env, &is_running) == -1)
				return (ft_quit_all_neg(&env));
			ft_original_draw(&env);
		}
		else if (is_running == 3)
		{
			while (SDL_PollEvent(&env.event))
				if ((ret = ft_handle_event(&env)) < 1)
				{
					if (ret == 0)
						ft_print_winner(&env);
					else if (ret == -1)
						ft_printf("Malloc allocation failed\n");
					else if (ret == -2)
					{
						is_running = 0;
						break ;
					}
				}
		}
	}
	return (ft_quit_all(&env));
}
