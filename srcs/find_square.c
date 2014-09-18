/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 04:06:40 by fschuber          #+#    #+#             */
/*   Updated: 2014/09/18 21:59:07 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"

int		cant_fit_square(int size, int x, int y, int **table)
{
	int	i;
	int	j;
	int	k;

	j = y;
	k = -1;
	while (j < y + size)
	{
		i = 0;
		while (table[j][i] >= 0)
		{
			if (table[j][i] >= x && table[j][i] < x + size)
				k = table[j][i] - x;
			i++;
		}
		if (k != -1)
			return (k);
		j++;
	}
	return (-1);
}

void	square_offset(int *x, int *offset)
{
	*x += (*offset + 1);
	*offset = 1;
}

void	set_to_neg(int *a, int *b)
{
	*a = -1;
	*b = -10;
}

int		*get_square(int **table, int a, int size)
{
	int	x;
	int	y;
	int	*answer;

	x = 0;
	y = 0;
	answer = malloc(3 * sizeof(int));
	set_to_neg(&answer[0], &answer[1]);
	while (++y <= table[0][0] - size + 1)
	{
		x = 0;
		while (x < table[0][4] - size)
		{
			a = cant_fit_square(size, x, y, table);
			if (a == -1)
			{
				answer[0] = x;
				answer[1] = y;
				answer[2] = size++;
			}
			else
				square_offset(&x, &a);
		}
	}
	return (answer);
}
