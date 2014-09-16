/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 06:20:12 by fschuber          #+#    #+#             */
/*   Updated: 2014/09/16 15:09:57 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"
#include "includes/protos.h"

int		is_in(int **table, int x, int y)
{
	int	i;

	i = 0;
	while (table[y][i] != -1)
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
	int	k;
	int	type;

	j = 1;
	k = 0;
	while (j <= size)
	{
		i = 0;
		while (i < size)
		{
			if (i >= solution[0] && i < solution[0] + solution[2]
					&& j >= solution[1] && j < solution[1] + solution[2])
				ft_putchar(table[0][3]);
			else if (is_in(table, i, j))
				ft_putchar (table[0][2]);
			else
				ft_putchar (table[0][1]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
