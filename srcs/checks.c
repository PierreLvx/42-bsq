/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/17 16:16:30 by plavaux           #+#    #+#             */
/*   Updated: 2014/09/18 16:10:42 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"
#include "includes/protos.h"

void		chk_map_chars(char buff, int *array)
{
	if (buff != array[1] && buff != array[2]
		&& buff != array[3] && buff != '\n')
	{
		ft_write_err("map error\n");
		exit (0);
	}
}

/*
void		check_line_len()
{

}
*/

/*
void		chk_map_min()
{
}
*/

void		chk_line_endings(int *array, int count, int file)
{
	if (count != array[0])
	{
		ft_write_err("map error\n");
		exit (0);
	}
	close(file);
}
