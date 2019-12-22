/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:13:10 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/21 21:13:34 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	init_text(t_visu *v)
{
	v->p1.color.r = 255;
	v->p1.color.g = 162;
	v->p1.color.b = 245;
	v->p2.color.r = 11;
	v->p2.color.g = 251;
	v->p2.color.b = 224;
	v->p1.name_rect.x = 40;
	v->p2.name_rect.x = v->map.limit.x + v->map.limit.w + 40;
	format_text(&v->p1, v);
	format_text(&v->p2, v);
}

void	format_text(t_player *p, t_visu *v)
{
	SDL_Surface	*tmp_surface;

	p->color.a = 255;
	p->name_rect.y = 30;
	p->name_rect.w = 15 * ft_strlen(p->name);
	p->name_rect.h = 40;
	p->score = 0;
	p->score_rect.x = p->name_rect.x + p->name_rect.w + 10;
	p->score_rect.y = p->name_rect.y;
	p->score_rect.h = p->name_rect.h;
	if (!(tmp_surface = TTF_RenderText_Blended(v->font, p->name, p->color)))
		sdl_exit_fail("RenderText()", v, &TTF_GetError);
	p->name_texture = SDL_CreateTextureFromSurface(v->renderer, tmp_surface);
	SDL_FreeSurface(tmp_surface);
	if (!p->name_texture)
		sdl_exit_fail("CreateTextureFromSurface()", v, &SDL_GetError);
}

char	*cut_playername(char *str)
{
	char			*tmp;
	uint_fast8_t	len;

	tmp = ft_strrchr(str, '/');
	if (tmp && tmp[1])
		str = &(tmp[1]);
	len = strchr_len(str, '.');
	if (len != 0)
		return (ft_strndup(str, len));
	return (ft_strdup(str));
}

void	read_playername(t_visu *v)
{
	char	*line;

	line = NULL;
	while (gnl_no_buff(0, &line) > 0 && *line != '$')
		ft_strdel(&line);
	if (!ft_strstr(line, ".filler"))
	{
		ft_strdel(&line);
		exit_fail("Invalid map or p1", v);
	}
	v->p1.name = cut_playername(line);
	ft_strdel(&line);
	if (!v->p1.name)
		exit_fail("Malloc : p1 name", v);
	while (gnl_no_buff(0, &line) > 0 && *line != '$')
		ft_strdel(&line);
	if (!ft_strstr(line, ".filler"))
	{
		ft_strdel(&line);
		exit_fail("Invalid p2", v);
	}
	v->p2.name = cut_playername(line);
	free(line);
	if (!v->p2.name)
		exit_fail("Malloc : p2 name", v);
}
