/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraintstable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 17:33:39 by fschuber          #+#    #+#             */
/*   Updated: 2014/09/16 13:36:39 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"
#include "includes/protos.h"

int	size_arrays(char *filename, int x, int n)
{
	int		file;
	int		*sizes;
	int		i;
	char	buff;

	i = 0;
	n = 0;
	file = open(filename, O_RDONLY);
	while (read(file, &buff, 1))
	{
		if (buff == '\n')
			n++;
		if (n == x + 1)
			break ;
	}
	if (x == -2)
		return (n);
	if (n < (x + 1))
		return (-1);
	while (read(file, &buff, 1) && buff != '\n')
	{
		if (buff == 'o')
			i++;
	}
	return (i);
}

int	*get_info(char *filename)
{
	int		*array;
	char	buff[8];
	int		file;
	char	*ptr;

	array = malloc(sizeof(int) * 4);
	file = open(filename, O_RDONLY);
	read(file, buff, 8);
	buff[8] = '\0';
	printf("buff %s\n", buff);
	array[0] = ft_atoi(buff);
	ptr = buff;
	while (*ptr >= 48 && *ptr <= 57)
		ptr++;
	printf("%d\n", array[0]);
	array[1] = *(ptr++);
	printf("%d\n", array[1]);
	array[2] = *(ptr++);
	printf("%d\n", array[2]);
	array[3] = *ptr;
	printf("%d\n", array[3]);
	return (array);
}

int	**allocate_array(char*filename, int j, int k)
{
	char	buff;
	int		i;
	int		file;
	int		**array;

	i = 1;
	array = malloc((size_arrays(filename, -2, 0) + 1) * sizeof(int*));
	array[0] = get_info(filename);
	while (size_arrays(filename, i, 0) != -1)
	{
		array[i] = malloc((size_arrays(filename, i, 0) + 1) * sizeof(int));
		i++;
	}
	file = open(filename, O_RDONLY);
	i = 0;
	while (read(file, &buff, 1))
	{
		if (buff == '\n')
			break ;
	}
	while (read(file, &buff, 1))
	{
		if (buff == 'o')
			array[j][k++] = i;
		if (buff == '\n')
		{
			array[j][k] = -1;
			j++;
			i = 0;
			k = 0;
		}
		else
			i++;
	}
	close(file);
	return (array);
}

int	**read_constraints(char *filename)
{
	int **array;

	array = allocate_array(filename, 1, 0);
	return (array);
}
