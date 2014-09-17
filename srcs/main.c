/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 15:29:24 by plavaux           #+#    #+#             */
/*   Updated: 2014/09/17 02:44:54 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"
#include "includes/protos.h"
#include <time.h>

int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
		while (i < argc)
		{
			solve_map(argv, i);
			i++;
		}
	if (argc == 1)
		ft_putstr("EXPECTING STDIN INPUT\n");
	return (0);
}

void	solve_map(char **argv, int i)
{
	int	**array;
	int	*solution;

	array = read_constraints(argv[i]);
	clock_t tic = clock();
	solution = get_square(array, 1, 0, 1);
	print_table(array, array[0][0], solution);
	clock_t toc = clock();
	printf("\033[1;31mRT = %f\033[0m\n", (double)(toc - tic) / CLOCKS_PER_SEC);
}
