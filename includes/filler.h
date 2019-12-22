/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 09:32:29 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/23 15:02:49 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct	s_item
{
	char			**tab;
	uint_fast8_t	w;
	uint_fast8_t	h;
}				t_item;

typedef struct	s_filler
{
	uint_fast8_t	me;
	uint_fast8_t	foe;
	t_item			map;
	t_item			piece;
}				t_filler;

typedef struct	s_tmp
{
	uint_fast8_t	i;
	uint_fast8_t	j;
	uint_fast8_t	crush;
	int_fast16_t	score;
}				t_tmp;

typedef	struct	s_dot
{
	uint_fast8_t	y;
	uint_fast8_t	x;
}				t_dot;

int_fast8_t		get_upleft(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t));
int_fast8_t		get_upright(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t));
int_fast8_t		get_downleft(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t));
int_fast8_t		get_downright(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t));
int_fast8_t		get_left(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t));
int_fast8_t		get_right(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t));
int_fast8_t		get_up(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t));
int_fast8_t		get_down(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t));
int_fast8_t		get_up_missing(t_filler s, t_dot d,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t));
int_fast8_t		get_down_missing(t_filler s, t_dot d,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t));
int_fast8_t		get_cross(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t));
int_fast8_t		get_x(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t));
int_fast8_t		get_square(t_filler s, t_dot d, uint_fast8_t jump,
	int_fast8_t (*f)(uint_fast8_t, uint_fast8_t, uint_fast8_t));
int_fast8_t		score_near(uint_fast8_t block, uint_fast8_t me,
	uint_fast8_t foe);
int_fast8_t		score_far(uint_fast8_t block, uint_fast8_t me,
	uint_fast8_t foe);
int_fast8_t		give_block_value(t_filler s, t_dot d);
void			generate_heatmap(t_filler s);
void			get_item(t_item *item, char *line, uint_fast8_t jump);
uint_fast8_t	check_block(t_filler s, t_tmp *tmp, int_fast16_t y,
	int_fast16_t x);
uint_fast8_t	check_placeable(t_filler s, int_fast16_t y, int_fast16_t x,
	int_fast16_t *best_score);
void			place_piece(t_filler s);
void			loop(t_filler s);

#endif
