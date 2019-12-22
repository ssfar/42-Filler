/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:10:14 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/21 21:01:27 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	load_piece(t_visu *v, uint_fast8_t color)
{
	uint_fast8_t	i;
	uint_fast8_t	j;

	i = 0;
	while (v->piece.tab[i])
	{
		v->piece.block.x = v->piece.limit.x + 1;
		j = 0;
		while (v->piece.tab[i][j])
		{
			if (v->piece.tab[i][j] == '*')
				set_piece_color(v, color, i, j);
			else if (SDL_SetRenderDrawColor(v->renderer, 20, 20, 20, 255) < 0)
				sdl_exit_fail("SetRenderDrawColor()", v, &SDL_GetError);
			if (SDL_RenderFillRect(v->renderer, &v->piece.block) < 0)
				sdl_exit_fail("RenderFillRect()", v, &SDL_GetError);
			v->piece.block.x += v->piece.block.w + 1;
			j++;
		}
		v->piece.block.y += v->piece.block.h + 1;
		i++;
	}
}

void	load_side(t_visu *v)
{
	uint_fast8_t	color;
	char			*line;

	v->piece.block.w = 1.5 * v->map.block.w;
	v->piece.block.h = 1.5 * v->map.block.h;
	v->piece.limit.w = (v->piece.block.w * v->piece.w) + v->piece.w + 1;
	v->piece.limit.h = (v->piece.block.h * v->piece.h) + v->piece.h + 1;
	v->piece.limit.y = v->p1.name_rect.y + v->p1.name_rect.h + 500;
	v->piece.block.y = v->piece.limit.y + 1;
	if (gnl_no_buff(0, &line) < 1)
		exit_fail("Can't gnl", v);
	v->piece.limit.x = v->p1.name_rect.x;
	color = 1;
	if (ft_strchr(line, 'X'))
	{
		v->piece.limit.x = v->p2.name_rect.x;
		color = 2;
	}
	free(line);
	if (SDL_SetRenderDrawColor(v->renderer, 255, 255, 255, 255) < 0)
		sdl_exit_fail("SetRenderDrawColor()", v, &SDL_GetError);
	if (SDL_RenderDrawRect(v->renderer, &v->piece.limit) < 0)
		sdl_exit_fail("RenderDrawRect()", v, &SDL_GetError);
	load_mapbox(v);
	load_piece(v, color);
}

void	load_score(t_player *p, TTF_Font *font, SDL_Renderer *renderer,
	t_visu *v)
{
	SDL_Surface		*tmp_surface;
	SDL_Texture		*tmp_texture;
	char			*score_str;

	p->score_rect.w = 15 * uintlen(p->score);
	if (!(score_str = utoa(p->score)))
		exit_fail("Malloc : utoa score", v);
	tmp_surface = TTF_RenderText_Blended(font, score_str, p->color);
	free(score_str);
	if (!tmp_surface)
		sdl_exit_fail("RenderText_Blended()", v, &TTF_GetError);
	tmp_texture = SDL_CreateTextureFromSurface(renderer, tmp_surface);
	SDL_FreeSurface(tmp_surface);
	if (!tmp_texture)
		sdl_exit_fail("TextureFromSurface()", v, &SDL_GetError);
	if (SDL_RenderCopy(renderer, tmp_texture, NULL, &(p->score_rect)) < 0)
	{
		SDL_DestroyTexture(tmp_texture);
		sdl_exit_fail("RenderCopy()", v, &SDL_GetError);
	}
	SDL_DestroyTexture(tmp_texture);
	if (SDL_RenderCopy(renderer, p->name_texture, NULL, &p->name_rect) < 0)
		sdl_exit_fail("RenderCopy()", v, &SDL_GetError);
}

void	load_mapbox(t_visu *v)
{
	if (v->prev_piece_found)
	{
		if (SDL_RenderDrawRect(v->renderer, &v->box) < 0)
			sdl_exit_fail("RenderFillRect()", v, &SDL_GetError);
	}
}

void	load_map(t_visu *v)
{
	uint_fast8_t	i;
	uint_fast8_t	j;

	v->prev_piece_found = 0;
	v->map.block.y = v->map.limit.y + 1;
	i = 0;
	if (!v->map.tab)
		v->map.tab = v->prev_map;
	while (v->map.tab[i])
	{
		j = 0;
		v->map.block.x = v->map.limit.x + 1;
		while (v->map.tab[i][j])
		{
			set_map_elem(i, j, v);
			if (SDL_RenderFillRect(v->renderer, &v->map.block) < 0)
				sdl_exit_fail("RenderFillRect()", v, &SDL_GetError);
			v->map.block.x += v->map.block.w + 1;
			j++;
		}
		v->map.block.y += v->map.block.h + 1;
		i++;
	}
}
