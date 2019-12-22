/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:24:44 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/23 20:30:57 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int_fast8_t	score_far(uint_fast8_t block, uint_fast8_t me, uint_fast8_t foe)
{
	if (block == me)
		return (-1);
	else if (block == foe)
		return (2);
	return (0);
}

int_fast8_t	score_near(uint_fast8_t block, uint_fast8_t me, uint_fast8_t foe)
{
	if (block == me)
		return (-2);
	else if (block == foe)
		return (3);
	return (0);
}

int_fast8_t	give_block_value(t_filler s, t_dot d)
{
	int_fast8_t	score;

	score = get_square(s, d, 1, &score_near);
	score += get_square(s, d, 2, &score_far);
	score += get_up_missing(s, d, &score_far);
	score += get_down_missing(s, d, &score_far);
	return (score);
}

void		generate_heatmap(t_filler s)
{
	t_dot	d;

	d.y = 0;
	while (d.y < s.map.h)
	{
		d.x = 0;
		while (d.x < s.map.w)
		{
			if (s.map.tab[d.y][d.x] == '.')
				s.map.tab[d.y][d.x] = give_block_value(s, d);
			d.x++;
		}
		d.y++;
	}
}
