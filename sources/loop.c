/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:02:22 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/21 17:49:25 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			get_item(t_item *item, char *line, uint_fast8_t jump)
{
	uint_fast8_t	i;

	item->h = ft_atoi(line);
	item->w = ft_atoi(ft_strrchr(line, ' '));
	i = 0;
	if ((item->tab = malloc(sizeof(*(item->tab)) * (item->h + 1))))
	{
		if (jump && get_next_line(0, &line) > 0)
			free(line);
		while (i < item->h && get_next_line(0, &line) > 0)
			item->tab[i++] = line + jump;
		item->tab[i] = NULL;
	}
}

uint_fast8_t	check_block(t_filler s, t_tmp *tmp, int_fast16_t y,
	int_fast16_t x)
{
	if (tmp->crush > 1 || y + tmp->i >= s.map.h || y + tmp->i < 0
	|| x + tmp->j >= s.map.w || x + tmp->j < 0
	|| s.map.tab[y + tmp->i][x + tmp->j] == s.foe)
		return (0);
	if (s.map.tab[y + tmp->i][x + tmp->j] == s.me)
		tmp->crush++;
	else
		tmp->score += s.map.tab[y + tmp->i][x + tmp->j];
	return (1);
}

uint_fast8_t	check_placeable(t_filler s, int_fast16_t y, int_fast16_t x,
	int_fast16_t *best_score)
{
	t_tmp	tmp;

	tmp.score = 0;
	tmp.crush = 0;
	tmp.i = -1;
	while (++tmp.i < s.piece.h)
	{
		tmp.j = -1;
		while (++tmp.j < s.piece.w)
			if (s.piece.tab[tmp.i][tmp.j] == '*')
			{
				if (!check_block(s, &tmp, y, x))
					return (0);
			}
	}
	if (!tmp.crush || tmp.crush > 1 || tmp.score <= *best_score)
		return (0);
	*best_score = tmp.score;
	return (1);
}

void			place_piece(t_filler s)
{
	int_fast16_t	y;
	int_fast16_t	x;
	int_fast16_t	best_y;
	int_fast16_t	best_x;
	int_fast16_t	best_score;

	best_y = 0;
	best_x = 0;
	best_score = -20000;
	y = 0 - s.piece.h;
	while (y < s.map.h)
	{
		x = 0 - s.piece.w;
		while (x < s.map.w)
		{
			if (check_placeable(s, y, x, &best_score))
			{
				best_y = y;
				best_x = x;
			}
			x++;
		}
		y++;
	}
	ft_printf("%d %d\n", best_y, best_x);
}

void			loop(t_filler s)
{
	char	*line;

	line = NULL;
	s.map.tab = NULL;
	s.piece.tab = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (line)
		{
			if (ft_strncmp(line, "Plateau", 4) == 0)
				get_item(&s.map, ft_strchr(line, ' '), 4);
			else if (ft_strncmp(line, "Piece", 2) == 0)
			{
				get_item(&s.piece, ft_strchr(line, ' '), 0);
				generate_heatmap(s);
				place_piece(s);
				s.map.tab = free_strtab_offset(s.map.tab, -4);
				s.piece.tab = free_strtab(s.piece.tab);
			}
			ft_strdel(&line);
		}
	}
	free_strtab_offset(s.map.tab, -4);
	free_strtab(s.piece.tab);
}
