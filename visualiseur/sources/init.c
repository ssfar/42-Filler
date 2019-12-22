/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:02:52 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/21 20:41:38 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	init_map(t_unit *map)
{
	map->block.w = 900 / map->w;
	map->block.h = 900 / map->h;
	map->limit.w = (map->block.w * map->w) + map->w + 1;
	map->limit.h = (map->block.h * map->h) + map->h + 1;
	map->limit.x = (WINW - map->limit.w) / 2;
	map->limit.y = (WINH - map->limit.h) / 2;
}

void	init_first_round(t_visu *v)
{
	read_playername(v);
	if (!read_round(&v->map, &v->piece))
		exit_fail("No round to read OR malloc error", v);
	init_map(&v->map);
	init_text(v);
	if (SDL_SetRenderDrawColor(v->renderer, 0, 0, 255, 255) < 0)
		sdl_exit_fail("SetRenderDrawColor()", v, &SDL_GetError);
	if (SDL_RenderDrawRect(v->renderer, &v->map.limit) < 0)
		sdl_exit_fail("RenderDrawRect()", v, &SDL_GetError);
	load_map(v);
	load_side(v);
	load_score(&v->p1, v->font, v->renderer, v);
	load_score(&v->p2, v->font, v->renderer, v);
	v->box.w = v->map.block.w;
	v->box.h = v->map.block.h;
}

void	init_struct(t_visu *v)
{
	v->window = NULL;
	v->renderer = NULL;
	v->p1.name = NULL;
	v->p1.name_texture = NULL;
	v->p2.name = NULL;
	v->p2.name_texture = NULL;
	v->map.tab = NULL;
	v->piece.tab = NULL;
	v->prev_map = NULL;
	v->font = NULL;
}

void	init(t_visu *v)
{
	init_struct(v);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		sdl_exit_fail("Init()", v, &SDL_GetError);
	if (!(v->window = SDL_CreateWindow("Filler Visualiseur",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINW, WINH, 0)))
		sdl_exit_fail("CreateWindow()", v, &SDL_GetError);
	if (!(v->renderer = SDL_CreateRenderer(v->window, -1,
		SDL_RENDERER_SOFTWARE)))
		sdl_exit_fail("CreateRenderer()", v, &SDL_GetError);
	if (TTF_Init() < 0)
		sdl_exit_fail("Init()", v, &TTF_GetError);
	if (!(v->font = TTF_OpenFont("/Library/Fonts/Arial.ttf", 30)))
		sdl_exit_fail("OpenFont()", v, &TTF_GetError);
	init_first_round(v);
	SDL_RenderPresent(v->renderer);
}
