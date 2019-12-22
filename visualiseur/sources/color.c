/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:25:30 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/21 19:08:12 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	set_piece_color(t_visu *v, uint_fast8_t color, uint_fast8_t i,
	uint_fast8_t j)
{
	if (v->prev_piece_found != 2)
	{
		v->box.y = i;
		v->box.x = j;
		v->prev_piece_found = 2;
	}
	if (color == 1)
	{
		if (SDL_SetRenderDrawColor(v->renderer, 255, 0, 0, 255) < 0)
			sdl_exit_fail("SetRenderDrawColor()", v, &SDL_GetError);
	}
	else if (SDL_SetRenderDrawColor(v->renderer, 0, 0, 255, 255) < 0)
		sdl_exit_fail("SetRenderDrawColor()", v, &SDL_GetError);
}

void	handle_last_placed(uint_fast8_t i, uint_fast8_t j, t_visu *v)
{
	if (v->map.tab[i][j] == 'o')
	{
		if (SDL_SetRenderDrawColor(v->renderer, 255, 0, 0, 255) < 0)
			sdl_exit_fail("SetRenderDrawColor()", v, &SDL_GetError);
		v->map.tab[i][j] = 'O';
		if (!v->prev_piece_found)
			v->p1.score++;
	}
	else if (v->map.tab[i][j] == 'x')
	{
		if (SDL_SetRenderDrawColor(v->renderer, 0, 0, 255, 255) < 0)
			sdl_exit_fail("SetRenderDrawColor()", v, &SDL_GetError);
		v->map.tab[i][j] = 'X';
		if (!v->prev_piece_found)
			v->p2.score++;
	}
	if (v->prev_map && v->prev_map[i][j] != '.')
		if (SDL_SetRenderDrawColor(v->renderer, 255, 255, 0, 255) < 0)
			sdl_exit_fail("SetRenderDrawColor()", v, &SDL_GetError);
	if (!v->prev_piece_found)
	{
		v->prev_piece_found = 1;
		v->box.x = v->map.block.x - (v->box.x * (v->map.block.w + 1));
		v->box.y = v->map.block.y - (v->box.y * (v->map.block.h + 1));
	}
}

void	set_map_elem(uint_fast8_t i, uint_fast8_t j, t_visu *v)
{
	if (v->map.tab[i][j] == 'O')
	{
		if (SDL_SetRenderDrawColor(v->renderer, 255, 162, 245, 255) < 0)
			sdl_exit_fail("SetRenderDrawColor()", v, &SDL_GetError);
	}
	else if (v->map.tab[i][j] == 'X')
	{
		if (SDL_SetRenderDrawColor(v->renderer, 11, 251, 224, 255) < 0)
			sdl_exit_fail("SetRenderDrawColor()", v, &SDL_GetError);
	}
	else if (v->map.tab[i][j] == '.')
	{
		if (SDL_SetRenderDrawColor(v->renderer, 20, 20, 20, 255) < 0)
			sdl_exit_fail("SetRenderDrawColor()", v, &SDL_GetError);
	}
	else
		handle_last_placed(i, j, v);
}
