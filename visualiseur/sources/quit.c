/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:08:26 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/21 20:59:00 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	quit(t_visu *v)
{
	if (SDL_WasInit(SDL_INIT_VIDEO))
	{
		if (TTF_WasInit())
		{
			TTF_CloseFont(v->font);
			SDL_DestroyTexture(v->p1.name_texture);
			SDL_DestroyTexture(v->p2.name_texture);
			TTF_Quit();
			free(v->p1.name);
			free(v->p2.name);
			v->prev_map = free_strtab_offset(v->prev_map, -4);
			v->map.tab = free_strtab_offset(v->map.tab, -4);
			v->piece.tab = free_strtab(v->piece.tab);
		}
		SDL_DestroyWindow(v->window);
		SDL_DestroyRenderer(v->renderer);
		SDL_Quit();
	}
}

void	exit_fail(char *str, t_visu *v)
{
	if (str)
		ft_dprintf(2, "[red]ERROR : %s[white]\n", str);
	quit(v);
	exit(EXIT_FAILURE);
}

void	sdl_exit_fail(char *str, t_visu *v, const char *(*get_err)(void))
{
	if (str)
		SDL_Log("SDL ERROR : %s > %s", str, get_err());
	quit(v);
	exit(EXIT_FAILURE);
}

void	print_winner(t_visu *v)
{
	SDL_Surface	*image;
	SDL_Texture	*texture;

	if (v->p1.score > v->p2.score)
	{
		if (!(image = SDL_LoadBMP("left.bmp")))
			sdl_exit_fail("LoadBMP()", v, &SDL_GetError);
	}
	else if (!(image = SDL_LoadBMP("right.bmp")))
		sdl_exit_fail("LoadBMP()", v, &SDL_GetError);
	texture = SDL_CreateTextureFromSurface(v->renderer, image);
	SDL_FreeSurface(image);
	if (!texture)
		sdl_exit_fail("CreateTextureFromSurface()", v, &SDL_GetError);
	v->box.w = 546;
	v->box.h = 112;
	v->box.x = (WINW - v->box.w) / 2;
	v->box.y = 20;
	if (SDL_RenderCopy(v->renderer, texture, NULL, &v->box) < 0)
	{
		SDL_DestroyTexture(texture);
		sdl_exit_fail("RenderCopy()", v, &SDL_GetError);
	}
	SDL_DestroyTexture(texture);
	SDL_RenderPresent(v->renderer);
}
