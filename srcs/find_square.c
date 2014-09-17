/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 04:06:40 by fschuber          #+#    #+#             */
/*   Updated: 2014/09/17 02:35:22 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"

int		cant_fit_square(int size, int x, int y, int **table)
{
	int	i;
	int	j;
	int	k;

	j = y;
	k = 0;
	while (j < y + size)
	{
		i = 0;
		while (table[j][i] != -1)
		{
			if (table[j][i] >= x && table[j][i] < x + size)
				k = table[j][i] - x;
			i++;
		}
		if (k != 0)
			return (k);
		j++;
	}
	return (0);
}

int		*get_square(int **table, int offset, int a)
{
	int	size;
	int	x;
	int	y;
	int	*answer;

	x = 0;
	y = 0;
	answer = malloc(3 * sizeof(int));
	size = 1;
	while (++y <= table[0][0] - size)
	{
		x = 0;
		while (x < table[0][0] - size)
		{
			if (!(a = cant_fit_square(size, x, y, table)))
			{
				answer[0] = x;
				answer[1] = y;
				answer[2] = size++;
				offset = a;
			}
			else
			{
				x += offset;
				offset = 1;
			}
		}
		//y++;
	}
	return (answer);
}
