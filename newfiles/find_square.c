/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 04:06:40 by fschuber          #+#    #+#             */
/*   Updated: 2014/09/16 12:38:41 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int can_fit_square(int size, int x, int y, int **table)
{
	int i;
	int j;

	j = y;
	while(j < y + size)
	{
		i = 0;
		while (table[j][i] != -1)
		{
			if (table[j][i] >= x && table[j][i] < x + size)
				return 0;
			i++;
		}
		j++;
	}
	return 1;
}

int *get_square(int **table)
{
	int size;
	int x;
	int y;
	int *answer;

	x = 0;
	y = 1;
	answer = malloc(3 * sizeof(int));
	size = 1;
	while (y <= table[0][0] - size)
	{
		x = 0;
		while (x < table[0][0] - size)
		{
			if (can_fit_square(size, x, y, table))
			{
				answer[0] = x;
				answer[1] = y;
				answer[2] = size++;
			}
			else
				x++;
		}
		y++;
	}
	return answer;
}
