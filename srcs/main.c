/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 15:29:24 by plavaux           #+#    #+#             */
/*   Updated: 2014/09/16 13:36:47 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"
#include "includes/protos.h"

int	main(void)
{
	int **array;
	int i;
	int j;
	int *solution;

	i = 0;
	array = read_constraints("test.txt");
	printf("0 - %d, 1 - %d, 2 - %d, 3 - %d", array[0][0], array[0][1], array[0][2], array[0][3]);
	solution = get_square(array);
	print_table(array, array[0][0], solution);
	return (0);
}

/*
int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	(void)argv;
	if (argc == 1)
		disp_stdin();
	else
	{
		while (i < argc)
		{
			file = open(argv[i], O_RDONLY);
			if (file >= 0)
			{
			while (read(file, &buffer, 1) != 0)
				write(1, &buffer, 1);
			}
		}
		close(file);
		i++;
	}
	return (0);
}
*/
