/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:59:59 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/21 21:17:38 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int				main(void)
{
	t_visu	v;

	init(&v);
	visu(&v);
	quit(&v);
}

void			visu(t_visu *v)
{
	SDL_bool	playing;
	SDL_bool	close;
	SDL_Event	event;

	playing = SDL_TRUE;
	close = SDL_FALSE;
	while (!close && SDL_WaitEvent(&event))
	{
		if (event.type == SDL_QUIT)
			close = SDL_TRUE;
		else if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				close = SDL_TRUE;
			else if (playing && event.key.keysym.sym == SDLK_RETURN)
				if (!display_round(v))
					playing = SDL_FALSE;
		}
	}
}

uint_fast8_t	display_round(t_visu *v)
{
	v->prev_map = free_strtab_offset(v->prev_map, -4);
	v->prev_map = v->map.tab;
	v->map.tab = NULL;
	if (!read_round(&v->map, &v->piece))
	{
		print_winner(v);
		return (0);
	}
	if (SDL_SetRenderDrawColor(v->renderer, 0, 0, 0, 255) < 0)
		sdl_exit_fail("SetRenderDrawColor()", v, &SDL_GetError);
	if (SDL_RenderClear(v->renderer) < 0)
		sdl_exit_fail("RenderClear()", v, &SDL_GetError);
	if (SDL_SetRenderDrawColor(v->renderer, 0, 0, 255, 255) < 0)
		sdl_exit_fail("SetRenderDrawColor()", v, &SDL_GetError);
	if (SDL_RenderDrawRect(v->renderer, &v->map.limit) < 0)
		sdl_exit_fail("RenderDrawRect()", v, &SDL_GetError);
	load_map(v);
	if (v->prev_map == v->map.tab)
		v->prev_map = NULL;
	load_side(v);
	load_score(&v->p1, v->font, v->renderer, v);
	load_score(&v->p2, v->font, v->renderer, v);
	SDL_RenderPresent(v->renderer);
	return (1);
}

void			get_unit(t_unit *unit, char *line, uint_fast8_t jump)
{
	uint_fast8_t	i;

	unit->h = ft_atoi(line);
	unit->w = ft_atoi(ft_strrchr(line, ' '));
	i = 0;
	if ((unit->tab = malloc(sizeof(*(unit->tab)) * (unit->h + 1))))
	{
		if (jump && gnl_no_buff(0, &line) > 0)
			free(line);
		while (i < unit->h && gnl_no_buff(0, &line) > 0)
			unit->tab[i++] = line + jump;
		unit->tab[i] = NULL;
	}
}

uint_fast8_t	read_round(t_unit *map, t_unit *piece)
{
	char	*line;

	line = NULL;
	while (gnl_no_buff(0, &line) > 0 && *line != '=')
	{
		if (line)
		{
			if (ft_strncmp(line, "Plateau", 4) == 0)
				get_unit(map, ft_strchr(line, ' '), 4);
			else if (ft_strncmp(line, "Piece", 2) == 0)
			{
				piece->tab = free_strtab(piece->tab);
				get_unit(piece, ft_strchr(line, ' '), 0);
				ft_strdel(&line);
				return (1);
			}
			ft_strdel(&line);
		}
	}
	ft_strdel(&line);
	return (0);
}
