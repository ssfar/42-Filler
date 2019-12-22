/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:18:02 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/21 17:48:08 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int_fast8_t	get_left(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t))
{
	int_fast8_t	score;

	score = 0;
	if (d.x - jump >= 0)
		score += f(s.map.tab[d.y][d.x - jump], s.me, s.foe);
	return (score);
}

int_fast8_t	get_right(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t))
{
	int_fast8_t	score;

	score = 0;
	if (d.x + jump < s.map.w)
		score += f(s.map.tab[d.y][d.x + jump], s.me, s.foe);
	return (score);
}

int_fast8_t	get_up(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t))
{
	int_fast8_t	score;

	score = 0;
	if (d.y - jump >= 0)
		score += f(s.map.tab[d.y - jump][d.x], s.me, s.foe);
	return (score);
}

int_fast8_t	get_down(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t))
{
	int_fast8_t	score;

	score = 0;
	if (d.y + jump < s.map.h)
		score += f(s.map.tab[d.y + jump][d.x], s.me, s.foe);
	return (score);
}
