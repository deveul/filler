/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:21:25 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/07 18:06:28 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "SDL.h"
# include "SDL_ttf.h"
# include "../libft/printf/ft_printf.h"
# include "../libft/libft/get_next_line.h"
# include <fcntl.h>

# define WIDTH 850
# define HEIGHT 850

typedef struct	s_piece
{
	int			height;
	int			width;
	char		**piece;
	int			**spiece;
	int			col;
	int			previouscol;
	int			x;
	int			y;
	int			xmin;
	int			xmax;
	int			ymin;
	int			ymax;
	int			trigger;
}				t_piece;

typedef struct	s_env
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*txt;
	SDL_Texture		*pc;
	SDL_Texture		*titlep1;
	SDL_Texture		*titlep2;
	SDL_Texture		*titlepiece;
	SDL_Texture		*titlescore;
	SDL_Texture		*originalscore;
	SDL_Texture		*txtwinner;
	SDL_Surface		*surf;
	SDL_Color		color;
	SDL_Event		event;
	SDL_Rect		rectnamep1;
	SDL_Rect		rectnamep2;
	SDL_Rect		rectpiece;
	SDL_Rect		rectscore;
	SDL_Rect		rectoriscore;
	SDL_Rect		rectwinner;
	TTF_Font		*font;
	t_piece			p;
	int				cptp1;
	int				cptp2;
	char			*p1;
	char			*p2;
	char			*namep1;
	char			*namep2;
	char			*score;
	char			*winner;
	int				width_map;
	int				height_map;
	int				**map;
	int				**piece;
}				t_env;

int				ft_first_parsing(t_env *env, int *is_running);
int				ft_init_env(t_env *env, int *is_running);
int				ft_handle_event(t_env *env);
int				ft_get_current_piece(t_piece *p, char *line, int color);
int				ft_next_move(t_env *env);
void			ft_original_draw(t_env *env);
void			ft_pick_color(t_env *env, int  r, int g, int b);
void			ft_draw_piece(t_env *env);
void			send_rect_to_fill(t_env *env, int i, int j, int color);
void			ft_actualize_score(t_env *env);

#endif
