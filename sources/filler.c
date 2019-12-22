/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <ssfar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:25:57 by ssfar             #+#    #+#             */
/*   Updated: 2019/10/21 17:46:53 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_filler	s;
	char		*line;

	line = NULL;
	if (get_next_line(0, &line) > 0 && ft_strlen(line) > 10 && *line == '$')
	{
		if (line[10] == '1')
		{
			s.me = 'O';
			s.foe = 'X';
		}
		else
		{
			s.me = 'X';
			s.foe = 'O';
		}
		free(line);
		loop(s);
	}
	else if (line)
		free(line);
}
