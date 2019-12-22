/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 07:22:04 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/21 17:04:44 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# define WINW 2080
# define WINH 1280
# include <SDL.h>
# include <SDL_ttf.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef	struct	s_player
{
	uint_fast16_t	score;
	SDL_Rect		limit;
	SDL_Rect		block;
	SDL_Rect		name_rect;
	SDL_Rect		score_rect;
	SDL_Color		color;
	SDL_Texture		*name_texture;
	char			*name;
}				t_player;

typedef struct	s_unit
{
	char			**tab;
	uint_fast8_t	w;
	uint_fast8_t	h;
	SDL_Rect		limit;
	SDL_Rect		block;
}				t_unit;

typedef	struct	s_visu
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	TTF_Font		*font;
	char			**prev_map;
	t_unit			map;
	t_unit			piece;
	t_player		p1;
	t_player		p2;
	uint_fast8_t	prev_piece_found;
	SDL_Rect		box;
}				t_visu;

void			visu(t_visu *v);
uint_fast8_t	display_round(t_visu *v);
void			get_unit(t_unit *unit, char *line, uint_fast8_t jump);
uint_fast8_t	read_round(t_unit *map, t_unit *piece);
void			quit(t_visu *v);
void			exit_fail(char *str, t_visu *v);
void			sdl_exit_fail(char *str, t_visu *v,
	const char *(*get_err)(void));
void			print_winner(t_visu *v);
void			load_piece(t_visu *v, uint_fast8_t color);
void			load_side(t_visu *v);
void			load_score(t_player *p, TTF_Font *font, SDL_Renderer *renderer,
	t_visu *v);
void			load_mapbox(t_visu *v);
void			load_map(t_visu *v);
void			init_map(t_unit *map);
void			init_first_round(t_visu *v);
void			init_struct(t_visu *v);
void			init(t_visu *v);
void			init_text(t_visu *v);
void			format_text(t_player *p, t_visu *v);
char			*cut_playername(char *str);
void			read_playername(t_visu *v);
void			set_piece_color(t_visu *v, uint_fast8_t color, uint_fast8_t i,
	uint_fast8_t j);
void			handle_last_placed(uint_fast8_t i, uint_fast8_t j, t_visu *v);
void			set_map_elem(uint_fast8_t i, uint_fast8_t j, t_visu *v);

#endif
