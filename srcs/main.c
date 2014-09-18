/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 15:29:24 by plavaux           #+#    #+#             */
/*   Updated: 2014/09/18 05:23:16 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"
#include "includes/protos.h"

void	solve_map(char **argv, int i)
{
	int	**array;
	int	*solution;

	array = read_constraints(argv[i]);
	solution = get_square(array, 1, 0, 1);
	print_table(array, array[0][0], solution);
}

void	solve_map_stdin(void)
{
	int **array;
	int *solution;

	array = read_stdin();
	solution = get_square(array, 1, 0, 1);
	print_table(array, array[0][0], solution);
}

int     main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
		while (i < argc)
		{
			solve_map(argv, i);
			i++;
		}
	if (argc == 1)
		solve_map_stdin();
	return (0);
}
