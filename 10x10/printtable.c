/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 06:20:12 by fschuber          #+#    #+#             */
/*   Updated: 2014/09/16 07:01:03 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_in(int **table, int x, int y)
{
	int i;

	i = 0;
	while(table[y][i] != -1)
	{
		if (table[y][i] == x)
			return 1;
		i++;
	}
	return 0;
}

void print_table(int **table, int size, int *solution)
{
	int i;
	int j;
	int k;
	int type;

	j = 0;
	k = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (i >= solution[0] && i < solution[0] + solution[2] && j >= solution[1] && j < solution[1] + solution[2])
				ft_putchar('x');
			else if (is_in(table, i, j))
				ft_putchar ('o');
			else
				ft_putchar ('.');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
