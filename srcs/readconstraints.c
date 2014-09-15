/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readconstraints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 17:33:39 by fschuber          #+#    #+#             */
/*   Updated: 2014/09/15 19:21:28 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"

t_point create_point(int x, int y)
{
	t_point new;

	new.x = x;
	new.y = y;
	return (new);
}

t_const *allocate_array(char *filename, int j, int index)
{
	char buff;
	int i;
	int file;
	t_const *array;

	file = open(filename, RDONLY);
	while(read(f, buff, 1))
		i++;
	close(file);
	array = malloc((i + 1) * sizeof(t_const));
	file = open(filename, RDONLY);
	i = 0;
	while (read(f, buff, 1))
	{
		if (buff == 10)
		{
			j++;
			i = 0;
		}
		if (buff == 'o')
			array[index++] = create_point(i, j);
	}
	array[index] = create_point(-1, -1);
	return (array);
}

t_const *read_constraints(char *filename)
{
	t_const *array;

	array = allocate_array(filename, 0, 0);
	return (array);
}
