/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 06:20:12 by fschuber          #+#    #+#             */
/*   Updated: 2014/09/18 17:06:26 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"

int		is_in(int **table, int x, int y)
{
	int	i;

	i = 0;
	while (table[y][i] >= 0)
	{
		if (table[y][i] == x)
			return (1);
		i++;
	}
	return (0);
}

void	print_table(int **table, int size, int *solution)
{
	int	i;
	int	j;

	j = 1;
	while (j <= size)
	{
		i = 0;
		while (i < table[0][4])
		{
			if (i >= solution[0] && i < solution[0] + solution[2]
					&& j >= solution[1] && j < solution[1] + solution[2])
				write(1, &table[0][3], 1);
			else if (is_in(table, i, j))
				write(1, &table[0][2], 1);
			else
				write(1, &table[0][1], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}
