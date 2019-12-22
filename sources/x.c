/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:19:49 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/21 17:46:41 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int_fast8_t	get_upleft(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t))
{
	int_fast8_t	score;

	score = 0;
	if (d.y - jump >= 0 && d.x - jump >= 0)
		score += f(s.map.tab[d.y - jump][d.x - jump], s.me, s.foe);
	return (score);
}

int_fast8_t	get_upright(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t))
{
	int_fast8_t	score;

	score = 0;
	if (d.y - jump >= 0 && d.x + jump < s.map.w)
		score += f(s.map.tab[d.y - jump][d.x + jump], s.me, s.foe);
	return (score);
}

int_fast8_t	get_downleft(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t))
{
	int_fast8_t	score;

	score = 0;
	if (d.y + jump < s.map.h && d.x - jump >= 0)
		score += f(s.map.tab[d.y + jump][d.x - jump], s.me, s.foe);
	return (score);
}

int_fast8_t	get_downright(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t))
{
	int_fast8_t	score;

	score = 0;
	if (d.y + jump < s.map.h && d.x + jump < s.map.w)
		score += f(s.map.tab[d.y + jump][d.x + jump], s.me, s.foe);
	return (score);
}
