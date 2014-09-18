/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraintstable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 17:33:39 by fschuber          #+#    #+#             */
/*   Updated: 2014/09/18 03:02:13 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"
#include "includes/protos.h"

int			*size_arrays(char *filename, int x, int *array)
{
	int		file;
	int		*sizes;
	int		i;
	char	buff;

	i = 0;
	sizes = malloc(sizeof(int) * (x + 1));
	while (i < x)
		sizes[i++] = 0;
	sizes[x] = -1;
	i = 0;
	file = open(filename, O_RDONLY);
	while (read(file, &buff, 1))
		if (buff == '\n')
			break ;
	while (read(file, &buff, 1) && i < x)
	{
		chk_map_chars(buff, array);
		if (buff == array[2])
			sizes[i]++;
		if (buff == '\n')
			i++;
	}
	return (sizes);
}

int			*get_info(char *filename)
{
	int		*array;
	char	buff[20];
	int		file;
	char	*ptr;

	array = malloc(sizeof(int*) * 5);
	file = open(filename, O_RDONLY);
	read(file, buff, 20);
	array[0] = ft_special_atoi(buff);
	ptr = buff;
	while (*ptr >= 48 && *ptr <= 57)
		ptr++;
	array[1] = *(ptr++);
	array[2] = *(ptr++);
	array[3] = *ptr;
	return (array);
}

int			return_minus_sizex(int *i, int *k, int *sizex)
{
	int temp;

	*sizex = *i - 1;
	temp = *i;
	*i = 0;
	*k = 0;
	return (-1 * (temp + 1));
}

int			**allocate_array(char*filename, int j, int k, int i)
{
	char	buff;
	int		*sizes;
	int		file;
	int		**array;

	sizes = get_info(filename);
	array = malloc((sizes[0] + 1) * sizeof(int*));
	array[0] = sizes;
	sizes = size_arrays(filename, array[0][0], array[0]);
	while (sizes[++i] != -1)
		array[i + 1] = malloc((sizes[i] + 1) * sizeof(int));
	free(sizes);
	file = open(filename, O_RDONLY);
	while (read(file, &buff, 1) && (buff != '\n'))
		i = 0;
	while (read(file, &buff, 1) && ++i)
	{
		if (buff == array[0][2])
			array[j][k++] = i - 1;
		if (buff == '\n')
			array[j++][k] = return_minus_sizex(&i, &k, &(array[0][5]));
	}
	close(file);
	return (array);
}

int			**read_constraints(char *filename)
{
	int		**array;

	array = allocate_array(filename, 1, 0, -1);
	return (array);
}
