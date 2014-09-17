/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/17 16:16:30 by plavaux           #+#    #+#             */
/*   Updated: 2014/09/18 00:38:56 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libs.h"
#include "includes/protos.h"

/*
** Lines of the same length
** At least one line of with one cell
** Each line ends with a \n
** In case of invalid map, return map error 
*/

void		chk_map_chars(char buff, int *array)
{
	if (buff != array[1] && buff != array[2] && buff != array[3] && buff != '\n')
	{
		ft_write_err("map error\n");
		exit (0);
	}
}
