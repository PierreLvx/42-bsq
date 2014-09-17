/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 04:06:40 by fschuber          #+#    #+#             */
/*   Updated: 2014/09/17 20:05:50 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"

double		cant_fit_square(int size, int x, int y, int **table)
{
	int	i;
	int	j;
	float	k;

	j = y;
	k = 0;
	while (j < y + size)
	{
		i = 0;
		while (table[j][i] >= 0)
		{
			if (table[j][i] >= x && table[j][i] < x + size)
				k = table[j][i] - x;
			i++;
		}
		if (k != 0)
		{
			while (j > 1)
				j = j/10;
			return (k + j);
		}
		j++;
	}
	return (0);
}

void	square_offset(int *x, double *offset)
{
	*x += (*offset + 1);
	*offset = 1;
}

int to_int(double a)
{
	while (a != (int)a)
	{
		a *= 10;
	}
	return a;
}

int		*get_square(int **table, double a, int size)
{
	int	x;
	int	y;
	int	*answer;
	int offsety;

	x = 0;
	y = 1;
	answer = malloc(3 * sizeof(int));
	while (y <= table[0][0] - size + 1)
	{
		x = 0;
		offsety = table[0][0];
		while (x <= table[0][5] - size)
		{
			a = cant_fit_square(size, x, y, table);
			if (to_int(a - (int)a) < (offsety + 1) && to_int(a - (int)a) != 0)
				offsety = to_int(a - (int)a) + 1;
			if ((int)a == 0)
			{
				answer[0] = x;
				answer[1] = y;
				answer[2] = size++;
			}
			else
				square_offset(&x, &a);
		}
		y = offsety;
	}
	return (answer);
}
