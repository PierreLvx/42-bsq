/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdintable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 03:40:21 by fschuber          #+#    #+#             */
/*   Updated: 2014/09/18 11:08:39 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"
#include "includes/protos.h"

char		*add_char(char c, char **array)
{
	char	*new;
	char	*ptr;
	int		i;
	int		size;

	ptr = *array;
	i = 0;
	size = 0;
	while (ptr[i])
		size++;
	new = malloc(sizeof(char) * (size + 2));
	i = -1;
	while (ptr[++i])
		new[i] = ptr[i];
	free(ptr);
	new[i++] = c;
	new[i] = '\0';
	return (new);
}

int			**read_stdin(void)
{
	int		**array;
	char	buff;
	char	*line;

	line = malloc(sizeof(char));
	line[0] = '\0';
	while (buff != '\n')
	{
		printf("%c", buff);
		read(0, &buff, 1);
		add_char(buff, &line);
	}
	printf("%s", line);
	array = malloc(sizeof(int*) * 10);
	return (array);
}
