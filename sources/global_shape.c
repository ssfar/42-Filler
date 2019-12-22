/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:22:22 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/21 17:46:56 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int_fast8_t	get_up_missing(t_filler s, t_dot d,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t))
{
	int_fast8_t	score;

	score = 0;
	if (d.y - 1 >= 0)
	{
		if (d.x + 2 < s.map.w)
			score += f(s.map.tab[d.y - 1][d.x + 2], s.me, s.foe);
		if (d.x - 2 >= 0)
			score += f(s.map.tab[d.y - 1][d.x - 2], s.me, s.foe);
		if (d.y - 2 >= 0)
		{
			if (d.x + 1 < s.map.w)
				score += f(s.map.tab[d.y - 2][d.x + 1], s.me, s.foe);
			if (d.x - 1 >= 0)
				score += f(s.map.tab[d.y - 2][d.x - 1], s.me, s.foe);
		}
	}
	return (score);
}

int_fast8_t	get_down_missing(t_filler s, t_dot d,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t))
{
	int_fast8_t	score;

	score = 0;
	if (d.y + 1 < s.map.h)
	{
		if (d.x + 2 < s.map.w)
			score += f(s.map.tab[d.y + 1][d.x + 2], s.me, s.foe);
		if (d.x - 2 >= 0)
			score += f(s.map.tab[d.y + 1][d.x - 2], s.me, s.foe);
		if (d.y + 2 < s.map.h)
		{
			if (d.x + 1 < s.map.w)
				score += f(s.map.tab[d.y + 2][d.x + 1], s.me, s.foe);
			if (d.x - 1 >= 0)
				score += f(s.map.tab[d.y + 2][d.x - 1], s.me, s.foe);
		}
	}
	return (score);
}

int_fast8_t	get_cross(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t))
{
	int_fast8_t	score;

	score = get_up(s, d, jump, f);
	score += get_down(s, d, jump, f);
	score += get_left(s, d, jump, f);
	score += get_right(s, d, jump, f);
	return (score);
}

int_fast8_t	get_x(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t))
{
	int_fast8_t	score;

	score = get_upleft(s, d, jump, f);
	score += get_upright(s, d, jump, f);
	score += get_downleft(s, d, jump, f);
	score += get_downright(s, d, jump, f);
	return (score);
}

int_fast8_t	get_square(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t))
{
	int_fast8_t	score;

	score = get_cross(s, d, jump, f);
	score += get_x(s, d, jump, f);
	return (score);
}
