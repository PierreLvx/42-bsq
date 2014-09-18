/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 15:29:24 by plavaux           #+#    #+#             */
/*   Updated: 2014/09/18 22:25:43 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"
#include "includes/protos.h"

void	solve_map(char **argv, int i)
{
	int	**array;
	int	*solution;

	array = read_constraints(argv[i]);
	if (array == NULL)
	{
		ft_write_err("map error\n");
		return ;
	}
	solution = get_square(array, 1, 0, 1);
	print_table(array, array[0][0], solution);
}

void	solve_map_stdin(void)
{
	int **array;
	int *solution;

	array = get_stdin();
	if (array == NULL)
	{
		ft_write_err("map error\n");
		return ;
	}
	solution = get_square(array, 1, 0, 1);
	print_table(array, array[0][0], solution);
}

int		main(int argc, char **argv)
{
	int i;
	int file;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			file = open(argv[i], O_RDONLY);
			if (file >= 0)
			{
				close(file);
				solve_map(argv, i);
			}
			else
				ft_write_err("map error\n");
			i++;
		}
	}
	if (argc == 1)
		solve_map_stdin();
	return (0);
}
