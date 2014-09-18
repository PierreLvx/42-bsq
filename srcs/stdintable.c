/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdintable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 03:40:21 by fschuber          #+#    #+#             */
/*   Updated: 2014/09/18 21:54:31 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"
#include "includes/protos.h"

char		*add_char(int i)
{
	char	*new;
	char	*array;
	int		size;
	char	buff;

	size = 1;
	array = malloc(1);
	while (read(0, &buff, 1) != -1 && buff != '\n')
	{
		i = -1;
		new = malloc(sizeof(char) * (size + 2));
		while (++i < size - 1)
			new[i] = array [i];
		free(array);
		new[i] = buff;
		new[i + 1] = '\0';
		size++;
		array = new;
		if (new[i] == 'n' && new[i - 1] == '\\')
			new[i - 1] = '\0';
	}
	return (array);
}

int			*get_info_stdin(char *firstline)
{
	int		*array;
	char	*ptr;

	array = malloc(sizeof(int) * 5);
	array[0] = ft_special_atoi(firstline);
	ptr = firstline;
	while (*ptr && *ptr != '\n')
		ptr++;
	ptr--;
	array[3] = *(ptr--);
	array[2] = *(ptr--);
	array[1] = *ptr;
	return (array);
}

int			*read_first_line(void)
{
	int		*info;
	char	*line;

	line = add_char(-1);
	info = get_info_stdin(line);
	return (info);
}

int			*get_line_obstacles(int **chars, int i, int size, int j)
{
	char	buff;
	int		*array;
	int		*new;

	new = malloc(1);
	while (read(0, &buff, 1) && (buff != '\n'))
	{
		array = new;
		if (buff == (*chars)[2])
		{
			i = -1;
			new = malloc(sizeof(int) * (size + 1));
			while (++i < size - 1)
				new[i] = array [i];
			free(array);
			new[i] = j;
			size++;
		}
		if (buff != (*chars)[1] && buff != (*chars)[2] && buff != (*chars)[3])
			return (NULL);
		j++;
	}
	new[i + 1] = -1 * j;
	(*chars)[4] = ((*chars)[4] == -1) ? j : (*chars)[4];
	return (j == (*chars)[4] && j > 0 && buff == '\n') ? new : NULL;
}

int			**get_stdin(void)
{
	int		**array;
	int		*info;
	int		i;

	i = 1;
	info = read_first_line();
	array = malloc(sizeof(int*) * (info[0] + 1));
	array[0] = info;
	array[0][4] = -1;
	while (i <= info[0])
	{
		array[i] = get_line_obstacles(&(array[0]), -1, 1, 0);
		if (array[i] == NULL)
		{
			array = NULL;
			return (array);
		}
		i++;
	}
	return (array);
}
