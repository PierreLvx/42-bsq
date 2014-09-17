/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 17:49:18 by plavaux           #+#    #+#             */
/*   Updated: 2014/09/18 00:34:51 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libs.h"

/*
** Print an error message to stderr
** @param		the message to print
*/

void	ft_write_err(char *str)
{
	write(2, str, ft_strlen(str));
}
