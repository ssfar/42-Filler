/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtab_iteri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:49:08 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/24 01:33:15 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Apply the function (f) to each characters of each strings of (tab) with their
** address and index provided to allow (f) to modify the strings if necessary.
*/

void	strtab_iteri(char **tab, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (tab && f)
	{
		i = 0;
		while (tab[i])
		{
			ft_striteri(tab[i], f);
			i++;
		}
	}
}
