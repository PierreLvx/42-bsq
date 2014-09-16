/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraintstable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 17:33:39 by fschuber          #+#    #+#             */
/*   Updated: 2014/09/16 04:00:44 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include  <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int size_arrays(char *filename, int x)
{
	int file;
	int *sizes;
	int n;
	int i;
	char buff;

	i = 0;
	n = 0;
	file = open(filename, O_RDONLY);
	while (read(file,&buff, 1))
	{
		printf("%d ", x);
		if (buff == '\n')
			n++;
		if (n == x + 1)
			break ;
	}
	if (x == -2)
		return n;
	if (n < (x + 1))
		return -1;
	while (read(file,&buff, 1) && buff != '\n')
	{
		if (buff == 'o')
			i++;
	}
	return i;
}

int **allocate_array(char*filename, int j,  int k)
{
	char buff;
	int i;
	int file;
	int **array;

	i = 0;	
	array = malloc(size_arrays(filename, -2) * sizeof (int*));
	while(size_arrays(filename, i) != -1)
	{
		array[i] = malloc((size_arrays(filename, i) + 1) * sizeof(int));
		printf("%d", size_arrays(filename, i));
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
		printf("j: %d i: %d  ", j, i);
		if (buff == 'o')
		{
			printf("o");
			array[j][k++] = i;
		}
		if (buff == '\n')
		{
			printf("new line");
			array[j][k] = -1;
			j++;
			i = 0;
			k = 0;
		}
		else
			i++;
			printf("\n");
	}
	close(file);
	return array;
}

int **read_constraints(char *filename)
{
	int **array;

	array = allocate_array(filename, 0, 0);
	return array;
}

int main(void)
{
	int **array;
	int i;
	int j;

	i = 0;
	array = read_constraints("test.txt");
	while(i < 10)
	{
		printf ("i : %d  ", i);
		j = 0;
		while(array[i][j] != -1)
		{
			printf("%d ", array[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}

	return (0);
}
