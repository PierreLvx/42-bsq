/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraintstable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 17:33:39 by fschuber          #+#    #+#             */
/*   Updated: 2014/09/17 01:31:54 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include  <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int *get_square(int **table, int offset, int a);

void ft_putchar(char c);

int *size_arrays(char *filename, int x)
{
	int file;
	int *sizes;
	int n;
	int i;
	char buff;

	i = 0;
	n = 0;
	sizes = malloc(sizeof(int) * (x + 1));
	while(i < x)
		sizes[i++] = 0;
	sizes[x] = -1;
	i = 0;
	file = open(filename, O_RDONLY);
	while (read(file,&buff, 1))
	{
		if (buff == '\n')
			break ;
	}
	while (read(file,&buff, 1) && i < x)
	{
		if (buff == 'o')
			sizes[i]++;
		if (buff == '\n')
			i++;
			}
	return sizes;
}

int *get_info(char *filename)
{
	int *array;
	char buff[8];
	int file;
	char *ptr;

	array = malloc(sizeof(int) * 4);
	file = open(filename, O_RDONLY);
	read(file, buff, 8);
	buff[8] = '\0';
	printf("buff %s\n", buff);
	array[0] = ft_atoi(buff);
	ptr = buff;
	while(*ptr >= 48 && *ptr <= 57)
		ptr++;
	printf("%d\n", array[0]);
	array[1] = *(ptr++);
	printf("%d\n", array[1]);
	array[2] = *(ptr++);
	printf("%d\n", array[2]);
	array[3] = *ptr;
	printf("%d\n", array[3]);
	return array;
}
int **allocate_array(char*filename, int j,  int k, int i)
{
	char buff;
	int *sizes;
	int file;
	int **array;

	i = 0;
	sizes = get_info(filename);
	array = malloc((sizes[0] + 1) * sizeof (int*));
	array[0] = sizes;
	sizes = size_arrays(filename, array[0][0]);
    while(sizes[i] != -1)
	{
		array[i+1] = malloc((sizes[i] + 1) * sizeof(int));
		i++;
	}
	ft_putchar('a');
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
		{
			array[j][k++] = i;
		}
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
	return array;
}

int **read_constraints(char *filename)
{
	int **array;

	array = allocate_array(filename, 1, 0, 1);
	return array;
}

int main(void)
{
	int **array;
	int i;
	int j;
	int *solution;

	i = 0;
	array = read_constraints("test.txt");
	printf("0 -  %d, 1 -  %d, 2 -  %d, 3 -  %d", array[0][0],array[0][1], array[0][2], array[0][3]);
	solution = get_square(array, 1, 0);
	print_table(array, array[0][0], solution);
	return (0);
}
